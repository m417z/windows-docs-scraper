# MINIPORT_WDI_RX_GET_MPDUS callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiRxGetMpdus handler function returns a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain. Each NET_BUFFER_LIST represents one MPDU.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_RX_GET_MPDUS** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PeerId` [in]

The peer ID.

### `ExTid` [in]

The extended TID.

### `ppNBL` [out]

Pointer to a pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain from the IHV miniport.

## Remarks

If *PeerId* and *ExTid* are not wildcards (for example, *PeerId* is not equal to 0xFFFF, *ExTid* is not equal to 31), all MPDUs in the chain are of the same peer ID and TID (in this case, TID is a valid 802.11 TID).

Each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) points to [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each NET_BUFFER structure represents one MSDU.

If an MPDU has an MSDU fragment as payload and defragmentation is not offloaded to target/TAL (or host-implemented FIPS mode is enabled), the corresponding NET_BUFFER_LIST has one NET_BUFFER that describes the MSDU fragment.

The data offset of each NET_BUFFER must be set to the start of the MAC header.

#### Examples

To define a MiniportWdiRxGetMpdus function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a MiniportWdiRxGetMpdus function that is named "MyRxGetMpdus", use the **MINIPORT_WDI_RX_GET_MPDUS** type as shown in this code example:

```
MINIPORT_WDI_RX_GET_MPDUS MyRxGetMpdus;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyRxGetMpdus(
    TAL_TXRX_HANDLE MiniportTalTxRxContext,
    WDI_PEER_ID PeerId,
    WDI_EXTENDED_TID ExTid,
    PNET_BUFFER_LIST *ppNBL
    )
  {...}
```

The **MINIPORT_WDI_RX_GET_MPDUS** function type is defined in the dot11wdi.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_WDI_RX_GET_MPDUS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI RX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-rx-path)

[WDI_EXTENDED_TID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-extended-tid)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)