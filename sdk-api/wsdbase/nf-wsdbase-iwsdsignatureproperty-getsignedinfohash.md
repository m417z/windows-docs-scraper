# IWSDSignatureProperty::GetSignedInfoHash

## Description

Gets the hash of a message signature.

## Parameters

### `pbSignedInfoHash` [out]

A pointer to a buffer that will be filled with the hash of the message signature.

### `pdwHashSize` [in, out]

On input, the size of *pbSignedInfoHash* in bytes. On output, *pdwHashSize* contains the actual size of the buffer that was written.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTAVAIL** | The message is not signed. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbSignedInfoHash* is not large enough to hold the information. *pdwHashSize* now specifies the required buffer size. |

## Remarks

This is the hash of the <SignedInfo> node. The <SignedInfo> xml node contains the SHA1 hashes of the various parts of the signature that is to be included in the signature. The final XML message signature is computed by signing the hash of the <SignedInfo> node with the private key of the signing certificate.

If **NULL** is passed to *pbSignedInfoHash*, then **GetSignedInfoHash** will return the size of the buffer to allocate in the *pdwHashSize* parameter.

## See also

[IWSDSignatureProperty](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdsignatureproperty)