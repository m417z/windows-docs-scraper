# PxeRegisterCallback function

## Description

Registers callback functions for different notification events.

## Parameters

### `hProvider` [in]

**HANDLE** passed to the
[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) function.

### `CallbackType` [in]

Specifies the callback that is being registered.

| Value | Meaning |
| --- | --- |
| **PXE_CALLBACK_RECV_REQUEST**<br><br>0 | Register the [PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest) callback. This callback must be registered while the provider is processing the [PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) function or the provider will be shut down. |
| **PXE_CALLBACK_SHUTDOWN**<br><br>1 | Register the [PxeProviderShutdown](https://learn.microsoft.com/windows/desktop/Wds/pxeprovidershutdown) callback. This callback must be registered while the provider is processing the [PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) function or the provider will be shut down. |
| **PXE_CALLBACK_SERVICE_CONTROL**<br><br>2 | Register the [PxeProviderServiceControl](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderservicecontrol) callback. |
| **PXE_CALLBACK_MAX**<br><br>3 | Used to determine an out-of-range index. Values greater than or equal to **PXE_CALLBACK_MAX** are not valid. |

### `pCallbackFunction` [in]

Address of the callback function. The function signature varies depending on the
*CallbackType* parameter.

### `pContext` [in]

Context value to be passed to the callback function.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize)

[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest)

[PxeProviderServiceControl](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderservicecontrol)

[PxeProviderShutdown](https://learn.microsoft.com/windows/desktop/Wds/pxeprovidershutdown)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)