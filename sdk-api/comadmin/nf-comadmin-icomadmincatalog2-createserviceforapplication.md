# ICOMAdminCatalog2::CreateServiceForApplication

## Description

Configures a COM+ application to run as a Windows service.

## Parameters

### `bstrApplicationIDOrName` [in]

The application ID or name of the application.

### `bstrServiceName` [in]

 The service name of the application. This name is the internal name used by the service control manager (SCM), not the display name.

### `bstrStartType` [in]

When to start the service. The valid arguments are the options of the *dwStartType* parameter of the [CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function. The arguments must be in quotes. The following are the valid arguments: SERVICE_BOOT_START, SERVICE_SYSTEM_START, SERVICE_AUTO_START, SERVICE_DEMAND_START, and SERVICE_DISABLED.

### `bstrErrorControl` [in]

The severity of the error if this service fails to start during startup. The error determines the action taken by the startup program if failure occurs. The valid arguments are the options of the *dwErrorControl* parameter of the [CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function. The arguments must be in quotes. The following are the valid arguments: SERVICE_ERROR_IGNORE, SERVICE_ERROR_NORMAL, SERVICE_ERROR_SEVERE, and SERVICE_ERROR_CRITICAL.

### `bstrDependencies` [in]

A list of dependencies for the service. There are two possible formats for the string: a standard null-delimited, double-null-terminated string (exactly as documented for [CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)); or a script-friendly list of service names separated by "\" (an invalid character to have in a service name). The rpcss service is implicit in this parameter and does not need to be specified.

### `bstrRunAs` [in]

The user name to run this service as. If this parameter is **NULL**, the service will run as Local Service.

### `bstrPassword` [in]

The password for the system user account. This parameter must be **NULL** if the service is configured to run as Local Service.

### `bDesktopOk` [in]

Indicates whether the service should be allowed to interact with the desktop. This parameter is valid only when the service is marked as Local Service and must be **FALSE** otherwise.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

A service created by this method can be removed using the [DeleteServiceForApplication](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-deleteserviceforapplication) method.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)