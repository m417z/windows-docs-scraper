# AuthzUninstallSecurityEventSource function

## Description

The **AuthzUninstallSecurityEventSource** function removes the specified source from the list of valid security event sources.

## Parameters

### `dwFlags` [in]

Reserved for future use; set this parameter to zero.

### `szEventSourceName` [in]

Name of the source to remove from the list of valid security event sources. This corresponds to the **szEventSourceName** member of the [AUTHZ_SOURCE_SCHEMA_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_source_schema_registration) structure that defines the source.

This function removes the source information from the registry. For more information about the registry keys and values affected, see the [AuthzInstallSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinstallsecurityeventsource) function.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AUTHZ_SOURCE_SCHEMA_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_source_schema_registration)

[AuthzInstallSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinstallsecurityeventsource)