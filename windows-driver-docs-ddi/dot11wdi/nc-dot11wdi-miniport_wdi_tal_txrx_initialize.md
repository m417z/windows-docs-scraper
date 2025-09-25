# MINIPORT_WDI_TAL_TXRX_INITIALIZE callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTalTxRxInitialize handler function initializes data structures in the TAL and exchanges datapath component handles between the UE and TAL. This is issued in the context of the driver initialization, and is issued prior to querying the firmware for the device capabilities.

This is a WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

**Note** You must declare the function by using the **MINIPORT_WDI_TAL_TXRX_INITIALIZE** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

Handle for the IHV miniport context.

### `NdisMiniportDataPathHandle` [in]

Handle for the IHV miniport to use in datapath indications.

### `NdisWdiDataPathApi` [in]

Pointer to the WDI data API function table.

### `pMiniportTalTxRxContext` [out]

The TAL device handle is a control path handle for the device (for example, MiniportContext). It is associated with the MiniportHandle, which used as context for NDIS API calls.

### `pMiniportDataHandlers` [in, out]

The UE initializes the NDIS Header field so the LE can determine the revision and size that is safe to initialize according to traditional NDIS versioning rules. The LE is responsible for updating the Header with the revision and size that the LE actually implements and supports before returning.

### `pMiniportWdiFrameMetadataExtraSpace` [out]

The LE sets the value pointed to by this parameter to the amount of space that WDI should reserve after the [WDI_FRAME_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_frame_metadata) for the LE to use.

## Return value

**Note** Non-**NDIS_STATUS_SUCCESS** return values indicate a generic failure.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the miniport driver successfully exchanged datapath component handles. |

## See also

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI general datapath interfaces](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-general-datapath-interfaces)

[WDI_FRAME_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_frame_metadata)