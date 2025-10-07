# PxeProviderServiceControl callback function

Called when a service control code is received by the WDS service. This callback function is registered by calling the [**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback) function with the *CallbackType* parameter set to **PXE\_CALLBACK\_SERVICE\_CONTROL**.

## Parameters

*pContext* \[in\]

Context value passed to the [**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback) function.

*dwControl*

Control code. For the list of possible values, see the *dwControl* parameter of the [*HandlerEx*](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) function.

## Return value

If the provider shutdown succeeds, the callback should return **ERROR\_SUCCESS**. In case of failure, an appropriate error code should be returned.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008, Windows Server 2003 with SP2 \[desktop apps only\]<br> |

## See also

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/win32/wds/windows-deployment-services-server-functions)

[**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback)

