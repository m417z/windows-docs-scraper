# OPEN_NDK_ADAPTER_HANDLER callback function

## Description

The *OpenNDKAdapterHandler* (*OPEN_NDK_ADAPTER_HANDLER*) function opens an NDK adapter instance on an NDK-capable NDIS miniport adapter.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. The miniport driver uses this context area to maintain state information for an NDIS miniport adapter.

### `Parameters` [in]

A pointer to an [NDIS_OPEN_NDK_ADAPTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/ns-ndisndk-_ndis_open_ndk_adapter_parameters) structure that defines the input parameters to open an [NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter) instance.

The [NDIS_OPEN_NDK_ADAPTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/ns-ndisndk-_ndis_open_ndk_adapter_parameters) structure must specify the NDKPI major version, and the lowest NDKPI minor version that the NDK consumer can support.

If the provider does not support the consumer-specified major version, the provider must fail the request with NDIS_STATUS_BAD_VERSION.

If the provider supports the consumer-specified major version and the specified minor version is less than or equal to the highest minor version that the provider supports, the provider must succeed the request and use the highest minor version that the provider supports.

 For example, if the consumer requests version 1.0, and the provider supports 1.1, the provider must report version 1.1 in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure and NDK object headers.

**Note** Higher minor versions at the provider are always fully backward-compatible with (that is, a superset of) lower minor versions.

If the provider supports the consumer-specified major version and the specified minor version is greater than the highest minor version that the provider supports, the provider must fail the request with NDIS_STATUS_BAD_VERSION.

### `ppNdkAdapter`

A pointer to a variable that holds the pointer to an [NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter) structure. On return from *OPEN_NDK_ADAPTER_HANDLER*, the **NDK_ADAPTER** structure referenced by *ppNdkAdapter* identifies the newly opened NDK adapter instance.

## Return value

*OPEN_NDK_ADAPTER_HANDLER* can return one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The NDK adapter instance was successfully opened. |
| **NDIS_STATUS_BAD_VERSION** | The requested version number is not supported. |
| **NDIS_STATUS_ADAPTER_NOT_READY** | The NDK functionality of the miniport adapter is not enabled. |
| **NDIS_STATUS_RESOURCES** | NDIS was unable to open the NDK adapter due to insufficient resources. |

## Remarks

*OPEN_NDK_ADAPTER_HANDLER* opens an [NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter) instance on an NDK-capable NDIS miniport adapter.
Multiple **NDK_ADAPTER** instances can be created on the same NDIS miniport adapter. Each **NDK_ADAPTER** instance contains a pointer to a table of dispatch functions that implement the NDK application programming interface.
The miniport driver calls the [CLOSE_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-close_ndk_adapter_handler) function to close the NDK adapter instance and release the associated resources.

## See also

[CLOSE_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-close_ndk_adapter_handler)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OPEN_NDK_ADAPTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/ns-ndisndk-_ndis_open_ndk_adapter_parameters)

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)