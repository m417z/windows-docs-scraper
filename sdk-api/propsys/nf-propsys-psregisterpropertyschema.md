# PSRegisterPropertySchema function

## Description

Informs the schema subsystem of the addition of a property description schema file.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

Pointer to the full file path, as a Unicode string, to the [property description schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry) (.propdesc) file on the local machine. This can be either a fully-specified full path, or a full path that includes environment variables such as `%PROGRAMFILES%`.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | All property descriptions in the schema were registered. |
| **E_ACCESSDENIED** | The calling context does not have proper privileges. |
| **INPLACE_S_TRUNCATED** | One or more property descriptions in the schema failed to register. The specific failures are logged in the application event log. |

## Remarks

This function is a wrapper API for the schema subsystem's implementation of [IPropertySystem::RegisterPropertySchema](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-registerpropertyschema). Call this function only when the file is first installed on the computer. Typically, a setup application calls this function after it installs the .propdesc file, which should be stored in the install directory of the application under Program Files. Multiple calls can be made to **IPropertySystem::RegisterPropertySchema** in order to register multiple schema files.

When registering property schema files, remember that they can be read by processes running as different users. Therefore, it is important to place a schema file in a location that grants read access to all users on the machine. Similarly, use the absolute path to the file in this function's *pszPath* parameter.

**Note** Because schemas are specific to the machine and cannot be registered for each individual user, registering a file path under user profiles is not supported on Windows Vista.

If a full or partial failure is encountered that prevents a property description from being loaded, the cause is recorded in the application event log. This function fails with E_ACCESSDENIED if the calling context does not have proper privileges, which includes write access to HKEY_LOCAL_MACHINE. It is the responsibility of the calling application to obtain privileges through User Account Control (UAC) mechanisms.