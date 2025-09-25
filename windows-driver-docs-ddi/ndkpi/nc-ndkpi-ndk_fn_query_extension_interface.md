# NDK_FN_QUERY_EXTENSION_INTERFACE callback function

## Description

The *NdkQqueryExtensionInterface* (*NDK_FN_QUERY_EXTENSION_INTERFACE*) function gets information about an NDK extension interface.

## Parameters

### `pNdkObject` [in]

 A pointer to the object header ([NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)) for the object being queried.

### `ExtensionInterfaceID` [in]

A pointer to the GUID that identifies the extension interface.

### `ExtensionInterfaceVersion` [in]

 The requested version ([NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version)) of the extension interface.

### `pExtensionInterface` [out]

A pointer to an [NDK_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_extension_interface) structure that the provider initialized if the function returns STATUS_SUCCESS.

## Return value

The *NdkQqueryExtensionInterface* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_NOT_SUPPORTED** | The function is not supported. |
| **Other status codes** | An error occurred. |

## Remarks

Each NDK object contains an *NdkQqueryExtensionInterface* (*NDK_FN_QUERY_EXTENSION_INTERFACE*) function pointer in its object type-specific function dispatch table. *NdkQqueryExtensionInterface* queries extended interfaces that are supported by the object type. There are currently no standard extended interfaces defined. An extension interface is identified by a GUID and represented as a pointer to a function dispatch table.

## See also

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq_dispatch)

[NDK_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_extension_interface)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)

[NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version)