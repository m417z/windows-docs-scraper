# IX509EndorsementKey::GetCertificateCount

## Description

Gets the count of the endorsement certificates in the key storage provider. You can only call the **GetCertificateCount** method after the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509endorsementkey-open) method has been successfully called.

## Parameters

### `ManufacturerOnly` [in]

True to return the count for only manufacturer certificates. False to return the count for only non-manufacturer certificates.

### `pCount` [out, retval]

The count of endorsement certificates from the key storage provider.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IX509EndorsementKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509endorsementkey)