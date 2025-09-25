# CLOSE_NDK_ADAPTER_HANDLER callback function

## Description

The *CloseNDKAdapterHandler* (*CLOSE_NDK_ADAPTER_HANDLER*) function closes an NDK adapter instance on an NDK-capable NDIS miniport adapter.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. The miniport driver uses this context area to maintain state information for an NDIS miniport adapter.

### `pNdkAdapter` [in]

A pointer to the [NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter) instance to close.

## Remarks

The *CLOSE_NDK_ADAPTER_HANDLER* function closes an [NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter) instance on an NDK-capable NDIS miniport adapter.
The miniport driver previously opened the NDK_ADAPTER instance by calling the [OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler) function.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler)