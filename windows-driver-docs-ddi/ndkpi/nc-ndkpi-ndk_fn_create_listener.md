# NDK_FN_CREATE_LISTENER callback function

## Description

The *NdkCreateListener* (*NDK_FN_CREATE_LISTENER*) function creates an NDK listener object.

## Parameters

### `pNdkAdapter` [in]

A pointer to an NDK adapter object ([NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)).

### `ConnectEvent` [in]

A pointer to the *NdkConnectEventCallback*  function ([NDK_FN_CONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_event_callback)) that the provider uses to notify the consumer for each incoming connection request.

### `ConnectEventContext` [in, optional]

A context value that the NDK provider passes back to the *NdkConnectEventCallback*  function that is specified in the *ConnectEvent* parameter.

### `CreateCompletion` [in]

A pointer to an *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that completes the creation of an NDK object.

### `RequestContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCreateCompletion* function that is specified in the *CreateCompletion* parameter.

### `ppNdkListener`

A pointer to the created NDK listener object ([NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)) is returned in this location if request succeeds without returning STATUS_PENDING. If *NdkCreateListener* returns STATUS_PENDING this parameter is ignored and the created object is returned with the callback that is specified in the *CreateCompletion* parameter.

## Return value

The *NdkCreateListener* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The listener object was created successfully and returned with the **ppNdkListener* parameter. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The provider will call the function specified in the *CreateCompletion* parameter([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) to complete the pending operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkCreateListener* function creates an NDK listener object. If the function returns STATUS_SUCCESS, the created object is returned in the *ppNdkListener* parameter. If *NdkCreateListener* returns STATUS_PENDING, the created object is returned by the *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that is specified in the *CreateCompletion* parameter.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_FN_CONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_event_callback)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)