// Fill out your copyright notice in the Description page of Project Settings.


#include "AStarNode.h"

 void UAStarNode::buildNode(float aF, float aG, float aH, int32 aPathLength, APathfindingTile * aPosition, UAStarNode * aParentNode)
{
	F = aF;
	G = aG;
	H = aH;
	pathLength = aPathLength;
	position = aPosition;
	parentNode = aParentNode;
} 

UAStarNode::UAStarNode()
{

}

UAStarNode::~UAStarNode()
{
}

float UAStarNode::getF()
{
	return F;
}

float UAStarNode::getG()
{
	return G;
}

float UAStarNode::getH()
{
	return H;
}

int32 UAStarNode::getPathLength() {
	return pathLength;
}

APathfindingTile* UAStarNode::getPosition()
{
	return position;
}

UAStarNode* UAStarNode::getParentNode() {
	return parentNode;
}