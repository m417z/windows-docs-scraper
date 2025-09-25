# MINIPORT_WDI_TX_TAL_SEND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTxTalSend handler function specifies an RA-TID or port queue to transmit from. The TxMgr uses this request instead of [MiniportWdiTxDataSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_data_send) for RA-TID queues with an extended TID in the IHV reserved range. It is issued in the context of a TX thread from the operating system, resume indication, or a work item.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TX_TAL_SEND** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID.

### `PeerId` [in]

The peer ID.

### `ExTid` [in]

The Extended TID.

### `NumQueueFrames` [in]

The queue length, in frames.

### `NumActiveFrames` [in]

The total number of frames in action (schedulable) queues.

### `bRobustnessFlag` [in]

The robustness flag. If the robustness flag is set to TRUE, the NIC ensures reliable delivery within a small number of retries by aggressively lowering the TX data rate used for the frame using CTS and/or other mechanisms.

## Remarks

In port queuing mode, *PeerId* and *ExTid* are set to wildcards.
In the context of the send request, the TxEngine issues [NdisWdiTxDequeueIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_dequeue_ind) to take ownership of a number of frames from the FIFO RA-TID queue and transfer them to the target. If it cannot dequeue any frames, the TxEngine issues [NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind) in the same context instead of *NdisWdiTxDequeueIndication*.

The TxEngine must issue a transfer complete and send complete indications to return ownership of any frames it dequeues to TxMgr. If the transfer complete contains a failure code, the TxEngine must not issue a send completion.

*PeerId* is set to wildcard if the port is configured as an access point/Wi-Fi Direct Group Owner and the frame has a group address as the receiver address.

On failure, the TxEngine completes the frame transfers to the target with the appropriate failure status.

#### Examples

To define a MiniportWdiTxTalSend function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a MiniportWdiTxTalSend function that is named "MyTxTalSend", use the **MINIPORT_WDI_TX_TAL_SEND** type as shown in this code example:

```
MINIPORT_WDI_TX_TAL_SEND MyTxTalSend;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyTxTalSend(
    TAL_TXRX_HANDLE MiniportTalTxRxContext,
    WDI_PORT_ID PortId,
    WDI_PEER_ID PeerId,
    WDI_EXTENDED_TID ExTid,
    UINT16 NumQueueFrames,
    UINT32 NumActiveFrames,
    BOOLEAN bRobustnessFlag
    )
  {...}
```

The **MINIPORT_WDI_TX_TAL_SEND** function type is defined in the dot11wdi.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_WDI_TX_TAL_SEND** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportWdiTxDataSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_data_send)

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[NdisWdiTxDequeueIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_dequeue_ind)

[NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI TX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tx-path)

[WDI_EXTENDED_TID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-extended-tid)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)