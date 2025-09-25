# NDK_FN_CREATE_MW callback function

## Description

The *NdkCreateMw* (*NDK_FN_CREATE_MW*) function creates an NDK memory window (MW) object.

## Parameters

### `pNdkPd` [in]

A pointer to an NDK protection domain (PD) object ([NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)).

### `CreateCompletion` [in]

A pointer to an *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that completes the creation of an NDK object.

### `RequestContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCreateCompletion* function that is specified in the *CreateCompletion* parameter.

### `ppNdkMw`

A pointer to a created MW object ([NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)) is returned in this location if the request succeeds without returning STATUS_PENDING. If the request returns STATUS_PENDING then this parameter is ignored and the created object is returned with the callback that is specified in the *CreateCompletion* parameter.

## Return value

The
*NdkCreateMw* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The MW object was created successfully and returned with the **ppNdkMw* parameter. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The provider will call the function specified in the *CreateCompletion* parameter([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) to complete the pending operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkCreateMw* function creates an NDK memory window (MW) object that can be used for bind requests. If the function returns STATUS_SUCCESS, the created object is returned in the *ppNdkMw* parameter. If *NdkCreateMw* returns STATUS_PENDING, the created object is returned by the *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that is specified in the *CreateCompletion* parameter.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)

[NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)