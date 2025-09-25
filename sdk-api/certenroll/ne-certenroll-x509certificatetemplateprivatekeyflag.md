# X509CertificateTemplatePrivateKeyFlag enumeration

## Description

The **X509CertificateTemplatePrivateKeyFlag** enumeration contains values that specify client actions regarding a private key.

## Constants

### `PrivateKeyRequireArchival:0x1`

Instructs the client to create a key archival certificate request.

### `PrivateKeyExportable:0x10`

Instructs the client to allow other applications to export the private key to a Personal Information Exchange (PFX) message. The message is typically saved in a file with a .pfx extension.

### `PrivateKeyRequireStrongKeyProtection:0x20`

Instructs the client to use additional protection for the private key.

### `PrivateKeyRequireAlternateSignatureAlgorithm:0x40`

If this flag is defined, the client must sign the certificate request by using the PKCS #1 version 2.1 signature format which requires that the hash algorithm OID be encoded into the signature parameters. If this flag is not defined the client must sign the certificate request by using the PKCS #1 version 1.5 signature format which requires that the hash and asymmetric algorithm object identifiers (OIDs) be combined into a single OID and that the signature parameters be set to **NULL**.

### `PrivateKeyRequireSameKeyRenewal:0x80`

### `PrivateKeyUseLegacyProvider:0x100`

### `PrivateKeyEKTrustOnUse:0x200`

### `PrivateKeyEKValidateCert:0x400`

### `PrivateKeyEKValidateKey:0x800`

### `PrivateKeyAttestNone:0`

### `PrivateKeyAttestPreferred:0x1000`

### `PrivateKeyAttestRequired:0x2000`

### `PrivateKeyAttestMask:0x3000`

### `PrivateKeyAttestWithoutPolicy:0x4000`

### `PrivateKeyServerVersionMask:0xf0000`

### `PrivateKeyServerVersionShift:16`

### `PrivateKeyHelloKspKey:0x100000`

### `PrivateKeyHelloLogonKey:0x200000`

### `PrivateKeyClientVersionMask:0xf000000`

### `PrivateKeyClientVersionShift:24`