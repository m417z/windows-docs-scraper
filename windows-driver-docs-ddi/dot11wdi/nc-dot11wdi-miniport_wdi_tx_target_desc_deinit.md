# MINIPORT_WDI_TX_TARGET_DESC_DEINIT callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
*MINIPORT_WDI_TX_TARGET_DESC_DEINIT* callback function informs the TxEngine that the target TX descriptors associated with the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) (NBLs) in the NBL chain are no longer needed and can be freed.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TX_TARGET_DESC_DEINIT** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in the [MINIPORT_WDI_TAL_TXRX_INITIALIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize) callback function.

### `pNBL` [in]

Pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain.

## Remarks

**Important** The IHV miniport is not permitted to make any indication in the context of this call.
The TxMgr serializes calls to [TxTargetDescDeInitHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

#### Examples

To define a *MINIPORT_WDI_TX_TARGET_DESC_DEINIT* callback function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MINIPORT_WDI_TX_TARGET_DESC_DEINIT* callback function that is named "MyTxTargetDescDeInit", use the **MINIPORT_WDI_TX_TARGET_DESC_DEINIT** type as shown in this code example:

```
MINIPORT_WDI_TX_TARGET_DESC_DEINIT MyTxTargetDescDeInit;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyTxTargetDescDeInit(
    TAL_TXRX_HANDLE MiniportTalTxRxContext,
    PNET_BUFFER_LIST pNBL
    )
  {...}
```

The **MINIPORT_WDI_TX_TARGET_DESC_DEINIT** function type is defined in the dot11wdi.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_WDI_TX_TARGET_DESC_DEINIT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI TX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tx-path)