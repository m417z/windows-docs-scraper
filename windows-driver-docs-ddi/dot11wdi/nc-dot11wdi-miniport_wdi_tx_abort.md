# MINIPORT_WDI_TX_ABORT callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTxAbort handler function aborts outstanding TX frames for a given port or peer, which includes initiating the completion of frames owned by the TAL/target. This request is issued to the TAL as part of handling [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) (adapter-wide TX abort), dot11 reset (port-wide abort), and after [NdisWdiPeerDeleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_delete_ind) if WDI is operating in peer queuing mode.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TX_ABORT** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID.

### `PeerId` [in]

The peer ID.

### `pWifiStatus` [out]

Pointer to a status of the MiniportWdiTxAbort, which should be set by the IHV miniport. See the *Remarks* section for more information.

## Remarks

A wildcard may be specified for the *PeerId* to stop TX on a port.

A wildcard for *PortId* and *PeerId* may be specified to stop TX across the adapter.

To complete the stop operation, the TAL must do the following steps.

1. Initiate the return of ownership of TX data buffers corresponding to the input parameters to the host. These frames should be completed by indicating transfer completion for all frames passed to the TxEngine in send requests and indicating [NdisWdiTxSendCompleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_complete_ind) for outstanding TX frames that require explicit send completion (if the TX frame was not transfer completed with a success code).
2. Return a success status, or return a pending status and issue [NdisWdiTxAbortConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_abort_confirm) later.

#### Examples

To define a MiniportWdiTxAbort function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a MiniportWdiTxAbort function that is named "MyTxAbort", use the **MINIPORT_WDI_TX_ABORT** type as shown in this code example:

```
MINIPORT_WDI_TX_ABORT MyTxAbort;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyTxAbort(
    TAL_TXRX_HANDLE MiniportTalTxRxContext,
    WDI_PORT_ID PortId,
    WDI_PEER_ID PeerId,
    NDIS_STATUS *pWifiStatus
    )
  {...}
```

The **MINIPORT_WDI_TX_ABORT** function type is defined in the dot11wdi.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_WDI_TX_ABORT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[NdisWdiPeerDeleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_delete_ind)

[NdisWdiTxAbortConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_abort_confirm)

[NdisWdiTxSendCompleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_complete_ind)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI TX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tx-path)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)