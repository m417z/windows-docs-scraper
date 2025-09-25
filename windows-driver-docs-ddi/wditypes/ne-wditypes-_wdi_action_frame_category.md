# _WDI_ACTION_FRAME_CATEGORY enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_ACTION_FRAME_CATEGORY enumeration defines the action frame categories.

## Constants

### `WDI_ACTION_FRAME_CATEGORY_PUBLIC`

Specifies a Public Action frame. It is used in:

* Inter-BSS and AP to unassociated-STA communications
* Intra-BSS communication
* GAS frames

### `WDI_ACTION_FRAME_CATEGORY_RADIO_MEASUREMENT`

Specifies a Radio Measurement Report frame. It is transmitted by a STA requesting another STA to make one or more measurements on one or more channels.

### `WDI_ACTION_FRAME_CATEGORY_FAST_BSS_TRANSITION`

Specifies a Fast BSS Transition Action frame. It is used by a currently-associated AP to enable fast BSS transitions over the DS. Over the DS transitions are not supported in Windows 10.

### `WDI_ACTION_FRAME_CATEGORY_WNM`

Specifies a Wireless Network Management Action frame. In Windows 10, it is only used for handling BSS Transition Management requests/responses.