# ITPhone::get_Display

## Description

The
**get_Display** method gets the display for the phone. In TAPI, the display is simply an NxM character buffer.

## Parameters

### `pbstrDisplay` [out]

The **BSTR** representation of the phone display. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[SetDisplay](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-setdisplay)