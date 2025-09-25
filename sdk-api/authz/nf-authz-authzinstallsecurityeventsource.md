# AuthzInstallSecurityEventSource function

## Description

The **AuthzInstallSecurityEventSource** function installs the specified source as a security event source.

## Parameters

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

### `pRegistration` [in]

A pointer to an [AUTHZ_SOURCE_SCHEMA_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_source_schema_registration) structure that contains information about the security event source to be added.

The members of the [AUTHZ_SOURCE_SCHEMA_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_source_schema_registration) structure are used as follows to install the security event source in the security log key:

* The **szEventSourceName** member is added as a registry key under

  ```
  HKEY_LOCAL_MACHINE
     SYSTEM
        CurrentControlSet
           Services
              EventLog
                 Security
  ```
* The **szEventMessageFile** member is added as the data in a REG_SZ value named **EventMessageFile** under the event source key.
* The **szEventAccessStringsFile** member is added as the data in a REG_SZ value named **ParameterMessageFile** under the event source key.
* If the registry path does not exist, it is created.

* If the **szEventSourceXmlSchemaFile** member is not **NULL**, it is added as the data in a REG_SZ value named **XmlSchemaFile** under the event source key. This value is not used.
* The **szExecutableImagePath** member may be set to **NULL**.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AUTHZ_SOURCE_SCHEMA_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_source_schema_registration)

[AuthzUninstallSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzuninstallsecurityeventsource)