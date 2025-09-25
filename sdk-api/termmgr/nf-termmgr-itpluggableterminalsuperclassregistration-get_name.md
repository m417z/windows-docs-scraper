# ITPluggableTerminalSuperclassRegistration::get_Name

## Description

The
**get_Name** method gets the friendly name for the terminal superclass.

## Parameters

### `pName` [out]

 Pointer to a **BSTR** representation of the friendly name. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pName* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITPluggableTerminalSuperclassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalsuperclassregistration)

[put_Name](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalsuperclassregistration-put_name)