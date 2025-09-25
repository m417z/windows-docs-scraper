# PSUnregisterPropertySchema function

## Description

Informs the schema subsystem of the removal of a property description schema file.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

Pointer to the full file path, as a Unicode string, to the property description schema (.propdesc) file on the local machine. This can be either a fully-specified full path, or a full path that includes environment variables such as `%PROGRAMFILES%`.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The schema was unregistered. |
| **E_ACCESSDENIED** | The calling context does not have proper privileges. |

## Remarks

This function is a wrapper for the schema subsystem's implementation of [IPropertySystem::UnregisterPropertySchema](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-unregisterpropertyschema). Call this method when the file is being uninstalled from the computer. Typically, a setup application calls this method before or after uninstalling the .propdesc file. This method can be called after the file no longer exists.

This function fails with a code of E_ACCESSDENIED if the calling context does not have proper privileges, which include write access to HKLM (HKEY_LOCAL_MACHINE). It is the responsibility of the calling application to obtain privileges through User Account Control (UAC) mechanisms.

## See also

[PSRegisterPropertySchema](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psregisterpropertyschema)