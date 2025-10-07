# PxeProviderShutdown callback function

Called to shutdown the provider. This function is registered by calling the [**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback) function with the *CallbackType* parameter set to **PXE\_CALLBACK\_SHUTDOWN**. After this function is called, the *hProvider* handle passed to the [*PxeProviderInitialize*](https://learn.microsoft.com/windows/win32/wds/pxeproviderinitialize) function is no longer valid.

## Parameters

*pContext* \[in\]

Context value passed to the [**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback) function.

## Return value

If the provider shutdown succeeds, the callback should return **ERROR\_SUCCESS**. In case of failure, an appropriate error code should be returned.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008, Windows Server 2003 with SP2 \[desktop apps only\]<br> |

## See also

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/win32/wds/windows-deployment-services-server-functions)

[*PxeProviderInitialize*](https://learn.microsoft.com/windows/win32/wds/pxeproviderinitialize)

[**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback)

