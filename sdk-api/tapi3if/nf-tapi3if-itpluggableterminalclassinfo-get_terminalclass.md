# ITPluggableTerminalClassInfo::get_TerminalClass

## Description

The
**get_TerminalClass** method gets the terminal's terminal class.

## Parameters

### `pTerminalClass` [out]

 The **BSTR** representation of the terminal's
[terminal class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class). The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). It should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalclassinfo)