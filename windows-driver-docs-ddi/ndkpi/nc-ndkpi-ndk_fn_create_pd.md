# NDK_FN_CREATE_PD callback function

## Description

The *NdkCreatePd* (*NDK_FN_CREATE_PD*) function creates an NDK protection domain (PD) object.

## Parameters

### `pNdkAdapter` [in]

A pointer to an NDK adapter object ([NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)).

### `CreateCompletion` [in]

A pointer to an *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that completes the creation of an NDK object.

### `RequestContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCreateCompletion* function that is specified in the *CreateCompletion* parameter.

### `ppNdkPd`

A pointer to a created PD object ([NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)) is returned in this location if the request succeeds without returning STATUS_PENDING. If the request returns STATUS_PENDING then this parameter is ignored and the created object is returned with the callback that is specified in the *CreateCompletion* parameter.

## Return value

The
*NdkCreatePd* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The PD object was created successfully and returned with the **ppNdkPd* parameter. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The provider will call the function specified in the *CreateCompletion* parameter([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) to complete the pending operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkCreatePd* function creates an NDK protection domain (PD) object. If the function returns STATUS_SUCCESS, the created object is returned in the *ppNdkPd* parameter. If *NdkCreatePd* returns STATUS_PENDING, the created object is returned by the *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that is specified in the *CreateCompletion* parameter.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)