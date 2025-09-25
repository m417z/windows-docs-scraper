# ITPluggableTerminalSuperclassRegistration::put_CLSID

## Description

The
**put_CLSID** method sets the CLSID used to **CoCreateInstance** the terminal.

## Parameters

### `bstrCLSID` [in]

The **BSTR** representation of the CLSID.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *bstrCLSID* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITPluggableTerminalSuperclassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalsuperclassregistration)

[get_CLSID](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalsuperclassregistration-get_clsid)