# CertIsValidCRLForCertificate function

## Description

The **CertIsValidCRLForCertificate** function checks a [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to find out if it is a CRL that would include a specific certificate if that certificate were revoked. If the CRL has an issuing distribution point (IDP) extension, the function checks whether that IDP is valid for the certificate being checked.

## Parameters

### `pCert` [in]

A pointer to a certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `pCrl` [in]

A pointer to a CRL. The function checks this CRL to determine whether it could contain the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) pointed to by *pCert*. The function does not look for the certificate in the CRL.

### `dwFlags` [in]

Currently not used and must be set to zero.

### `pvReserved` [in]

Currently not used and must be set to **NULL**.

## Return value

The function returns **TRUE** if the CRL is a valid CRL to be searched for the specific certificate. It returns **FALSE** if the CRL is not a valid CRL for searching for the certificate.

## Remarks

For the CRL to be valid for the certificate, the **CertIsValidCRLForCertificate** function does not require the CRL to be issued by the same [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) as the issuer of the certificate.