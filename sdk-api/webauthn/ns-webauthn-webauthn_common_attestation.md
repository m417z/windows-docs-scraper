## Description

The structure containing the common data for an attestation.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `pwszAlg`

The hash and padding algorithm. This won't be set for _fido-u2f_ which assumes **"ES256"**.

### `lAlg`

The COSE algorithm identifier. This value is a number identifying a cryptographic algorithm. The algorithm identifiers _should_ be values registered in the [IANA COSE Algorithms registry](https://w3c.github.io/webauthn/#biblio-iana-cose-algs-reg), for instance, -7 for "ES256" and -257 for "RS256".

### `cbSignature`

The signature that was generated for this attestation.

### `pbSignature`

A pointer to the signature that was generated for this attestation.

### `cX5c`

Array of X.509 DER encoded certificates. The first certificate is the signer, leaf certificate. This is set for **Full Basic Attestation**. If not set, then this is a **Self Attestation**.

### `pX5c`

A pointer to the array of X.509 certificates.

### `pwszVer`

A pointer to the version of the attestation statement. (This is set for tpm.)

### `cbCertInfo`

The size of the certificate information. (This is set for tpm.)

### `pbCertInfo`

A pointer to the certificate information. (This is set for tpm.)

### `cbPubArea`

The size of the public key area. (This is set for tpm.)

### `pbPubArea`

A pointer to the public key area. (This is set for tpm.)

## Remarks

## See also

[WEBAUTHN_CREDENTIAL_ATTESTATION](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential_attestation)

[WEBAUTHN_X5C](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_x5c)