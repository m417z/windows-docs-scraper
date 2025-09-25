# IMFTranscodeSinkInfoProvider::SetOutputFile

## Description

Sets the name of the encoded output file.

## Parameters

### `pwszFileName` [in]

Pointer to a null-terminated string that contains the name of the output file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The media sink will create a local file with the specified file name.

Alternately, you can call [IMFTranscodeSinkInfoProvider::SetOutputByteStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodesinkinfoprovider-setoutputbytestream) to specify a byte stream that will receive the transcoded data. These two methods are mutually exclusive.

## See also

[IMFTranscodeSinkInfoProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodesinkinfoprovider)