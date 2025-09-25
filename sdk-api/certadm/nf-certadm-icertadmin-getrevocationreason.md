# ICertAdmin::GetRevocationReason

## Description

The **GetRevocationReason** method returns the reason a certificate was revoked. This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

Before you call this method, you must call the
[IsValidCertificate](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-isvalidcertificate) method. For more information, see Remarks.

## Parameters

### `pReason` [out]

A pointer to a variable that will receive the revocation reason.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pReason* parameter is set to one of the values listed in the following table.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a value that specifies the reason the certificate was revoked. The value can be one of the following revocation reason codes (defined in Wincrypt.h).

| Return code | Description |
| --- | --- |
| **CRL_REASON_UNSPECIFIED** | No reason was specified for revocation. |
| **CRL_REASON_KEY_COMPROMISE** | It is known or suspected that the subject's private key or other aspects of the subject validated in the certificate are compromised. |
| **CRL_REASON_CA_COMPROMISE** | It is known or suspected that the CA's private key or other aspects of the CA validated in the certificate are compromised. |
| **CRL_REASON_AFFILIATION_CHANGED** | The subject's name or other information in the certificate has been modified but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_SUPERSEDED** | The certificate has been superseded, but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_CESSATION_OF_OPERATION** | The certificate is no longer needed for the purpose for which it was issued, but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_CERTIFICATE_HOLD** | The certificate has been placed on hold. |

## Remarks

Before you call **GetRevocationReason**, call the
[IsValidCertificate](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-isvalidcertificate) method to retrieve the disposition of the certificate. To call **GetRevocationReason**, you must receive a certificate disposition CA_DISP_REVOKED from this earlier call, indicating that the certificate has been revoked. The call to **IsValidCertificate** establishes the identity of the certificate whose revocation reason you want to retrieve.

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

```cpp
// The value for nDisp was set by
// a call to ICertAdmin2::IsValidCertificate.
if (CA_DISP_REVOKED == nDisp)
{
    // Variable to contain revocation reason.
    long       nReason;

    // Retrieve the revocation reason.
    hr = pCertAdmin->GetRevocationReason(&nReason);
    if (FAILED(hr))
    {
        printf("Failed GetRevocationReason [%x]\n", hr);
        goto error;
    }
    else
        printf("Revocation reason = %d\n", nReason );
}
```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[IsValidCertificate](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-isvalidcertificate)