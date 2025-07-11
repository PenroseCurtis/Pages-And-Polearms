// Fill out your copyright notice in the Description page of Project Settings.

#include "pathFinder.h"

float UPathFinder::calculateH(APathfindingTile * successorTile, APathfindingTile * destination)
{
	return (abs(successorTile->getYCoordinatePf() - destination->getYCoordinatePf()) + abs(successorTile->getXCoordinatePf() - destination->getXCoordinatePf())) / 16.0;
}

bool UPathFinder::shouldNodeBeAdded(UAStarNode * node, TArray<UAStarNode*> nodes)
{
	for (int i = 0; i < nodes.Num(); i++)
	{
		if (node->getPosition()->getXCoordinatePf() == nodes[i]->getPosition()->getXCoordinatePf() && 
			node->getPosition()->getYCoordinatePf() == nodes[i]->getPosition()->getYCoordinatePf() &&
			node->getG() >= nodes[i]->getG())
		{
			return false;
		}
	}
	return true;
}

FPathfindingResults UPathFinder::findPath(APathfindingTile* start, APathfindingTile* destination, int32 maxCost, int32 maxPathLength)
{
	TArray<UAStarNode*> openNodes = {};
	TSet<APathfindingTile*> closedTiles = {};
	UAStarNode* Q = NewObject<UAStarNode>();
	int32 lastFailure = 1;

	Q->buildNode(0, 0, 0, 0, start, Q);
	openNodes.Add(Q);
	UAStarNode* successor = nullptr;
	bool pathFound = false;
	int32 loopCount = 0;
	while (openNodes.Num() != 0 && loopCount < 1000)
	{
		Q = openNodes[0];
		loopCount++;
		for (int32 i = 0; i < openNodes.Num(); i++) {
			if (openNodes[i]->getF() < Q -> getF())
			{
				Q = openNodes[i];
			}
		}
		openNodes.Remove(Q);
		
		closedTiles.Add(Q->getPosition());
		for (int32 i = 0; i < 4; i++)
		{
			APathfindingTile* tile = Q->getPosition()->getNeighborPf(i);
			if (tile != nullptr && !closedTiles.Contains(tile))
			{
				float H = calculateH(tile, destination);
				float G = tile->getCostPf() + Q->getG();
				int32 pathLength = Q->getPathLength() + 1;
				if (maxCost > 0 && G > maxCost) {
					lastFailure = 2;
					continue;
				}
				else if (maxPathLength > 0 && pathLength > maxPathLength) {
					lastFailure = 3;
					continue;
				}

				successor = NewObject<UAStarNode>();
				successor->buildNode(G + H, G, H, pathLength, tile, Q);
				if (successor->getPosition() == destination) {
					pathFound = true;
					openNodes.Empty();
					break;
				}
				else if(
					!successor->getPosition()->getIsOccupiedPf() && 
					shouldNodeBeAdded(successor, openNodes)
				){
					openNodes.Add(successor);
				}
			}
		}
	}
	TArray<APathfindingTile*> pathOut = {};
	if (loopCount == 1000)
	{
		return FPathfindingResults({}, 4, 0, 0);
	}
	if (!pathFound)
	{
		return FPathfindingResults({}, lastFailure, 0, 0);
	}
	int32 costOut = successor->getG();
	int32 pathLength = successor->getPathLength();
	while (successor != successor->getParentNode())
	{
		pathOut.Insert(successor->getPosition(), 0);
		successor = successor->getParentNode();
	}
	return FPathfindingResults(pathOut, 0, pathLength, costOut);
}
