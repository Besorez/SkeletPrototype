#include "SPGameMode.h"

#include "SPPlayerState.h"
#include "SP/Characters/SPCharacter.h"

ASPGameMode::ASPGameMode()
{
	DefaultPawnClass = ASPCharacter::StaticClass();
	PlayerStateClass = ASPPlayerState::StaticClass();
}
