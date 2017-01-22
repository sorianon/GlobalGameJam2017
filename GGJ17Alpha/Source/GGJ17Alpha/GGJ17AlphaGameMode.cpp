// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "GGJ17Alpha.h"
#include "GGJ17AlphaGameMode.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "GGJPlayer.h"
=======
>>>>>>> master
=======
#include "GGJPlayer.h"
>>>>>>> c9a3cde4418fb2b9f257a669341eefe4e9b820e4
#include "GGJ17AlphaPawn.h"

AGGJ17AlphaGameMode::AGGJ17AlphaGameMode()
{
	// set default pawn class to our flying pawn
<<<<<<< HEAD
<<<<<<< HEAD
	DefaultPawnClass = AGGJPlayer::StaticClass();
=======
	DefaultPawnClass = AGGJ17AlphaPawn::StaticClass();
>>>>>>> master
=======
	DefaultPawnClass = AGGJPlayer::StaticClass();
>>>>>>> c9a3cde4418fb2b9f257a669341eefe4e9b820e4
}
