# INDESPolicy::VerifyRequest

## Description

Verifies the NDES certificate request for submission to the CA.

## Parameters

### `pctbRequest` [in]

The encoded PKCS#10 request.

### `pctbSigningCertEncoded` [in]

The valid signing certificate for a renewal request.

### `pwszTemplate` [in]

The template being requested for, as determined by NDES.

### `pwszTransactionId` [in]

The SCEP request transaction ID.

### `pfVerified` [out, retval]

True if the challenge is verified; otherwise false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INDESPolicy](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-indespolicy)