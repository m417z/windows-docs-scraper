# MINIPORT_WDI_TX_TAL_QUEUE_IN_ORDER callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTxTalQueueInOrder handler function notifies the TAL target that one or more paused RA/TID queues (with **WDI_TX_PAUSE_REASON_PS**) is ready to transmit.

This means:

* Each of the queues has no outstanding TX frames with TAL/target.
* All frames that were TX completed with **WDI_TxFrameStatus_SendPostponed** were inserted in the RA-TID queue in the correct order.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TX_TAL_QUEUE_IN_ORDER** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PeerId` [in]

The peer ID.

### `ExTidBitmask` [in]

The Extended TID bitmask.

## Remarks

The TAL/target waits for this notification before issuing a TX restart indication to a paused queue with **WDI_TX_PAUSE_REASON_PS**.

**Note** **WDI_TxFrameStatus_SendPostponed** is not allowed when **TargetPriorityQueueing** is TRUE, so this request is never made when in that mode.

#### Examples

To define a MiniportWdiTxTalQueueInOrder function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a MiniportWdiTxTalQueueInOrder function that is named "MyTxTalQueueInOrder", use the **MINIPORT_WDI_TX_TAL_QUEUE_IN_ORDER** type as shown in this code example:

```
MINIPORT_WDI_TX_TAL_QUEUE_IN_ORDER MyTxTalQueueInOrder;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyTxTalQueueInOrder(
    TAL_TXRX_HANDLE MiniportTalTxRxContext,
    WDI_PEER_ID PeerId,
    UINT32 ExTidBitmask
    )
  {...}
```

The **MINIPORT_WDI_TX_TAL_QUEUE_IN_ORDER** function type is defined in the dot11wdi.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_WDI_TX_TAL_QUEUE_IN_ORDER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_TXRX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_capabilities)

[WDI_TX_FRAME_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_frame_status)

[WDI_TX_PAUSE_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_pause_reason)