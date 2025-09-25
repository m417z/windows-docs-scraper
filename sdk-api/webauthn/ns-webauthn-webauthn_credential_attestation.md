## Description

Contains the attestation data for a credential.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `pwszFormatType`

The attestation format type.

### `cbAuthenticatorData`

The size of **pbAuthenticatorData**.

### `pbAuthenticatorData`

The authenticator data that was created for this credential.

### `cbAttestation`

The size of the CBOR encoded attestation information.

### `pbAttestation`

The encoded CBOR attestation information.

### `dwAttestationDecodeType`

The attestation decode type.

### `pvAttestationDecode`

The attestation decode value.

### `cbAttestationObject`

The size of **pbAttestationObject**.

### `pbAttestationObject`

The CBOR encoded Attestation Object to be returned to the Relying Party.

### `cbCredentialId`

The size of **pbCredentialId**.

### `pbCredentialId`

The CredentialId bytes extracted from the Authenticator Data. Used by Edge to return to the Relying Party.

### `Extensions`

The extensions for this credential.

### `dwUsedTransport`

One of the **WEBAUTHN_CTAP_TRANSPORT** bits is passed, according to the transport that was used.

### `bEpAtt`

The EP attestation flag.

### `bLargeBlobSupported`

Indicates whether the authenticator supports large blob attestation.

### `bResidentKey`

Indicates whether the relying party requires a resident key.

## Remarks

The **pvAttestationDecode** depends on the **dwAttestationDecodeType**:

| **Decode type** | **Decode value** |
|----------|----------|
| **WEBAUTHN_ATTESTATION_DECODE_NONE** | **NULL** - not able to decode the CBOR attestation information |
| **WEBAUTHN_ATTESTATION_DECODE_COMMON** | **PWEBAUTHN_COMMON_ATTESTATION** |

## See also

[WebAuthNAuthenticatorMakeCredential](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatormakecredential)