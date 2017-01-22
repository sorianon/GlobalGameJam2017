// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "GGJam2017.h"
#include "GGJam2017GameMode.h"
#include "GGJam2017Pawn.h"

AGGJam2017GameMode::AGGJam2017GameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AGGJam2017Pawn::StaticClass();
}
