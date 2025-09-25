# ITPluggableTerminalClassRegistration::get_Name

## Description

The
**get_Name** method gets the terminal's friendly name.

## Parameters

### `pName` [out]

The **BSTR** representation of the friendly name. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalClassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalclassregistration)

[put_Name](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalclassregistration-put_name)