# IPropertySystem::RegisterPropertySchema

## Description

Informs the schema subsystem of the addition of a property description schema file.

## Parameters

### `pszPath` [in]

Type: **LPCWSTR**

Pointer to the file path for the .propdesc file on the local machine.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates schema is registered. |
| **E_ACCESSDENIED** | Indicates calling context does not have proper privileges. |
| **INPLACE_S_TRUNCATED** | Indicates one or more of the property descriptions in the schema was not registered. |

## Remarks

This method informs the schema subsystem of the addition of a property description schema (.propdesc) file, using a file path to the .propdesc file on the local computer. Call this method only when the file has first been installed on the computer. Typically, a setup application calls this method after installing the .propdesc file, which should be stored in the install directory of the application under "Program Files". Multiple calls may be made to [IPropertySystem::RegisterPropertySchema](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-registerpropertyschema) in order to batch-register multiple schema files.

If a failure is encountered that prevents a property description from getting loaded, the cause will be recorded in the application event log. This method fails with E_ACCESSDENIED if the calling context does not have proper privileges, which include write access to HKLM (HKEY_LOCAL_MACHINE). It is the responsibility of the calling application to obtain privileges via limited user account (LUA) mechanisms.

## See also

[IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem)