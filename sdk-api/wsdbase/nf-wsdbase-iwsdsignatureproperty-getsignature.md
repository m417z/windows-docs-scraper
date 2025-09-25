# IWSDSignatureProperty::GetSignature

## Description

Gets the signature of a message.

## Parameters

### `pbSignature` [out]

A pointer to a buffer that will be filled with the signature of the message.

### `pdwSignatureSize` [in, out]

On input, the size of *pbSignature* in bytes. On output, *pdwSignatureSize* contains the actual size of the buffer that was written.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTAVAIL** | The message is not signed. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbSignature* is not large enough to hold the information. *pdwSignatureSize* now specifies the required buffer size. |

## Remarks

If **NULL** is passed to *pbSignature*, then **GetSignature** will return the size of the buffer to allocate in the *pdwSignatureSize* parameter.

## See also

[IWSDSignatureProperty](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdsignatureproperty)