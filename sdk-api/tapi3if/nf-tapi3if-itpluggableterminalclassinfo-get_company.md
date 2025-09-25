# ITPluggableTerminalClassInfo::get_Company

## Description

The
**get_Company** method gets the name of the company that issued this pluggable terminal.

## Parameters

### `pCompany` [out]

The **BSTR** representation of the terminal's company name. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalclassinfo)