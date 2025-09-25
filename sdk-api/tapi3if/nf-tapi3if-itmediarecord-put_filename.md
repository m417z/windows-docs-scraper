# ITMediaRecord::put_FileName

## Description

The
**put_FileName** method sets the name of the file to record.

## Parameters

### `bstrFileName` [in]

The **BSTR** representation of the file name.

#### - bAppendIfExists [in]

If this flag is set to **TRUE**, and a file with this name already exists, the new data will be appended to the file. If this flag is set to **FALSE**, and the file exists, the new data will overwrite the old data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITMediaRecord](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmediarecord)

[get_FileName](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itmediarecord-get_filename)