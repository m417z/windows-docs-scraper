# ITPluggableTerminalSuperclassRegistration::get_CLSID

## Description

The
**get_CLSID** method gets the CLSID used to **CoCreateInstance** the terminal.

## Parameters

### `pCLSID` [out]

 The **BSTR** representation of the CLSID. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCLSID* parameter is not a valid pointer. |

## See also

[ITPluggableTerminalSuperclassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalsuperclassregistration)

[put_CLSID](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalsuperclassregistration-put_clsid)