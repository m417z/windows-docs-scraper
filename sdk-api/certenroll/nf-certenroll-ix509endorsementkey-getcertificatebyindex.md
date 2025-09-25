# IX509EndorsementKey::GetCertificateByIndex

## Description

Gets the endorsement certificate associated with the endorsement key from the key storage provider for the specified index. You can only call the **GetCertificateByIndex** method after the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509endorsementkey-open) method has been successfully called.

## Parameters

### `ManufacturerOnly` [in]

True to get manufacturer endorsement keys only; otherwise false. The default is false.

### `dwIndex` [in]

The index of the requested endorsement certificate.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode-encoding applied to the endorsement certificate. The default value is XCN_CRYPT_STRING_BASE64.

### `pValue` [out, retval]

The endorsement certificate requested.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IX509EndorsementKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509endorsementkey)