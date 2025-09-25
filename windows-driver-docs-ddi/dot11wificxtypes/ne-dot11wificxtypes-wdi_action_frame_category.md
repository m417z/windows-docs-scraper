## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_ACTION_FRAME_CATEGORY** enumeration defines action frame categories.

## Constants

### `WDI_ACTION_FRAME_CATEGORY_SPECTRUM_MANAGEMENT:0`

Spectrum Management Action frame category.

### `WDI_ACTION_FRAME_CATEGORY_QOS:1`

QoS Action frame category.

### `WDI_ACTION_FRAME_CATEGORY_RESERVED:2`

Reserved.

### `WDI_ACTION_FRAME_CATEGORY_BLOCK_ACK:3`

Block Acknowledgement Action frame category.

### `WDI_ACTION_FRAME_CATEGORY_PUBLIC:4`

Public Action frame category. It is used in:

* Inter-BSS and AP to unassociated-STA communications
* Intra-BSS communication<
* GAS frames

### `WDI_ACTION_FRAME_CATEGORY_RADIO_MEASUREMENT:5`

Radio Measurement Report frame category. It is transmitted by a STA requesting another STA to make one or more measurements on one or more channels.

### `WDI_ACTION_FRAME_CATEGORY_FAST_BSS_TRANSITION:6`

Fast BSS Transition Action frame category. It is used by a currently-associated AP to enable fast BSS transitions over the DS. Over the DS transitions are not supported in Windows 10.

### `WDI_ACTION_FRAME_CATEGORY_HT:7`

HT Action frame category.

### `WDI_ACTION_FRAME_CATEGORY_SA_QUERY:8`

SA Query Action frame category.

### `WDI_ACTION_FRAME_CATEGORY_PROTECTED_DUAL_OF_PUBLIC_ACTION:9`

Protected Dual of Public Action frame category.

### `WDI_ACTION_FRAME_CATEGORY_WNM:10`

Wireless Network Management Action frame category. In Windows 10, it is only used for handling BSS Transition Management requests/responses.

### `WDI_ACTION_FRAME_CATEGORY_UNPROTECTED_WNM:11`

Unprotected Wireless Network Management Action frame category.

### `WDI_ACTION_FRAME_CATEGORY_ROBUST_AV_STREAMING:19`

Robust AV Streaming Action frame category.

## Remarks

## See also