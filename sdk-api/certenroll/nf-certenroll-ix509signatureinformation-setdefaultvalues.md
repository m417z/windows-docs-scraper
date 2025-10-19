# IX509SignatureInformation::SetDefaultValues

## Description

The **SetDefaultValues** method specifies a default hashing algorithm used to create a digest of the certificate request prior to signing.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The hashing algorithm OID could not be found. |

## Remarks

If the hash algorithm is already set, this method performs no action. If the hash algorithm has not been specified, this method sets it to XCN_OID_OIWSEC_sha1 and clears the signature algorithm cache.

## See also

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)