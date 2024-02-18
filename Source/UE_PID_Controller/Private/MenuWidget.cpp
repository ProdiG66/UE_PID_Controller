// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.


#include "MenuWidget.h"

AMenuWidget::AMenuWidget() {
	PrimaryActorTick.bCanEverTick = true;
}

void AMenuWidget::SetRocket(UPIDControllerMenu* Menu) {
	Menu->Rocket = Rocket;
}
