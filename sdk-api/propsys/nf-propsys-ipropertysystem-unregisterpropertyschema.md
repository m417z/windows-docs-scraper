# IPropertySystem::UnregisterPropertySchema

## Description

Informs the schema subsystem of the removal of a property description schema (.propdesc) file, using a file path to the .propdesc file on the local machine.

## Parameters

### `pszPath` [in]

Type: **LPCWSTR**

Pointer to the file path for the .propdesc file on the local machine.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates schema is unregistered. |
| **E_ACCESSDENIED** | Indicates calling context does not have proper privileges. |

## Remarks

Call this method when the file is being uninstalled from the machine. Typically, a setup application calls this method before or after uninstalling the .propdesc file. This method can be called after the file no longer exists.

Call [IPropertySystem::RefreshPropertySchema](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-refreshpropertyschema) in order for the newly-unregistered schema files to be unincorporated from the search index and the schema subsystem cache.

This method fails with E_ACCESSDENIED if the calling context does not have proper privileges, which include write access to the local machine. It is the caller's responsibility to obtain privileges via least-privileged user account (LUA) mechanisms.

## See also

[IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem)