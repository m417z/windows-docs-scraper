# IRdcSignatureReader::ReadHeader

## Description

The
**ReadHeader** method
reads the signature header and returns a copy of the parameters
used to generate the signatures.

## Parameters

### `rdc_ErrorCode` [out]

Address of a [RDC_ErrorCode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdc_errorcode) enumeration that will
receive any RDC-specific error code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcSignatureReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcsignaturereader)

[RDC_ErrorCode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdc_errorcode)