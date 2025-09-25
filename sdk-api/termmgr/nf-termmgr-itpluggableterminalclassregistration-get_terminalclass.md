# ITPluggableTerminalClassRegistration::get_TerminalClass

## Description

The
**get_TerminalClass** method gets the terminal's terminal class.

## Parameters

### `pTerminalClass` [out]

The **BSTR** representation of the
[terminal class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class). The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalClassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalclassregistration)

[put_TerminalClass](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalclassregistration-put_terminalclass)