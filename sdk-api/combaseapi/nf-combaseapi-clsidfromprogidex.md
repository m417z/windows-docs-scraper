# CLSIDFromProgIDEx function

## Description

Triggers automatic installation if the COMClassStore policy is enabled.

This is analogous to the behavior of [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) when neither CLSCTX_ENABLE_CODE_DOWNLOAD nor CLSCTX_NO_CODE_DOWNLOAD are specified.

## Parameters

### `lpszProgID` [in]

A pointer to the ProgID whose CLSID is requested.

### `lpclsid` [out]

Receives a pointer to the retrieved CLSID on return.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The CLSID was retrieved successfully. |
| **CO_E_CLASSSTRING** | The registered CLSID for the ProgID is invalid. |
| **REGDB_E_WRITEREGDB** | An error occurred writing the CLSID to the registry. See Remarks below. |

## Remarks

CLSCTX_ENABLE_CODE_DOWNLOAD enables automatic installation of missing classes through IntelliMirror/Application Management from the Active Directory. If this flag is not specified, the COMClassStore Policy ("Download missing COM components") determines the behavior (default: no download).

If the COMClassStore Policy enables automatic installation, CLSCTX_NO_CODE_DOWNLOAD can be used to explicitly disallow download for an activation.

If either of the following registry values are enabled (meaning set to 1), automatic download of missing classes is enabled:

* **HKEY_CURRENT_USER\Software\Policies\Microsoft\Windows\App Management**\**COMClassStore**
* **HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows\App Management**\**COMClassStore**

## See also

[ProgIDFromCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-progidfromclsid)