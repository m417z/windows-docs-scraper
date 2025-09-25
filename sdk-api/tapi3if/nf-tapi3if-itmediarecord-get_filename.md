# ITMediaRecord::get_FileName

## Description

The
**get_FileName** method retrieves the name of the file that was used for recording by this terminal.

## Parameters

### `pbstrFileName` [out]

The **BSTR** representation of the file name. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITMediaRecord](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmediarecord)

[put_FileName](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itmediarecord-put_filename)