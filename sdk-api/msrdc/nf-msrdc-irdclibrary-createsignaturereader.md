# IRdcLibrary::CreateSignatureReader

## Description

The **CreateSignatureReader** method
creates a signature reader to allow an application to decode the contents of a signature
file.

## Parameters

### `iFileReader` [in]

An [IRdcFileReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcfilereader) interface pointer initialized to read the signatures.

### `iSignatureReader` [out]

Pointer to a location that will receive an
[IRdcSignatureReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcsignaturereader) interface pointer. On a
successful return the interface will be initialized on return. Callers must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcFileReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcfilereader)

[IRdcLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdclibrary)

[IRdcSignatureReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcsignaturereader)