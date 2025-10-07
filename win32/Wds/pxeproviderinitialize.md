# PxeProviderInitialize callback function

An export from a provider dynamic-link library (DLL) that initializes the provider and prepares it to receive client requests. Providers are required to export the *PxeProviderInitialize* function. Any callbacks to the provider must be registered with a call to the [**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback) function during the processing of *PxeProviderInitialize*. On the return of this function, the provider must be fully initialized and ready to process client requests.

## Parameters

*hProvider* \[in\]

Handle to the provider instance. This handle must be stored by the provider and used in any subsequent calls. This handle is valid until the [*PxeProviderShutdown*](https://learn.microsoft.com/windows/win32/wds/pxeprovidershutdown) callback function is called.

*hProviderKey* \[in\]

Handle to a registry key where provider configuration information is to be stored.

## Return value

If the provider initialization succeeds, the callback should return **ERROR\_SUCCESS**. In case of failure, an appropriate error code should be returned.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008, Windows Server 2003 with SP2 \[desktop apps only\]<br> |

## See also

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/win32/wds/windows-deployment-services-server-functions)

[*PxeProviderShutdown*](https://learn.microsoft.com/windows/win32/wds/pxeprovidershutdown)

