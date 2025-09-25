# _WDI_RX_INDICATION_LEVEL enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_RX_INDICATION_LEVEL enumeration defines the RX indication levels.

## Constants

### `WDI_RX_INDICATION_DISPATCH_GENERAL`

Used for subsequent data indications in a DPC. **WDI_RX_INDICATION_DISPATCH_FIRST_OF_DPC** is used for the first data indication of a DPC.

### `WDI_RX_INDICATION_DISPATCH_FIRST_OF_DPC`

Used for the first data indication ([NdisWdiRxInorderDataIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_rx_inorder_data_ind)) of a DPC.

### `WDI_RX_INDICATION_FROM_RX_RESUME_FRAMES`

Used when making data indications in the context of [MiniportWdiRxResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_resume).

### `WDI_RX_INDICATION_PASSIVE`

Used when making data indications at passive level.

### `WDI_RX_INDICATION_FLAG_RESOURCES`

Bitwise OR’d with other enum values to cause RxMgr to set **NDIS_RECEIVE_FLAG_RESOURCES**.

### `WDI_RX_INDICATION_DISPATCH_GENERAL_WITH_LOW_RESOURCES`

Bitwise OR of **WDI_RX_INDICATION_FLAG_RESOURCES** and **WDI_RX_INDICATION_DISPATCH_GENERAL**.

### `WDI_RX_INDICATION_DISPATCH_FIRST_OF_DPC_WITH_LOW_RESSOURCES`

Bitwise OR of **WDI_RX_INDICATION_FLAG_RESOURCES** and **WDI_RX_INDICATION_DISPATCH_FIRST_OF_DPC**.

### `WDI_RX_INDICATION_FROM_RX_RESUME_FRAMES_WITH_LOW_RESOURCES`

Bitwise OR of **WDI_RX_INDICATION_FLAG_RESOURCES** and **WDI_RX_INDICATION_FROM_RX_RESUME_FRAMES**.

### `WDI_RX_INDICATION_PASSIVE_WITH_LOW_RESOURCES`

Bitwise OR of **WDI_RX_INDICATION_FLAG_RESOURCES** and **WDI_RX_INDICATION_PASSIVE**.