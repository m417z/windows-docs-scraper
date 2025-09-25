# JAVA_TRUST structure

## Description

Contains trust information.

## Members

### `cbSize`

The size of this structure, in bytes.

### `flag`

Reserved.

### `fAllActiveXPermissions`

Indicates whether all ActiveX permissions were requested.

### `fAllPermissions`

Indicates whether all Java permissions were requested.

### `dwEncodingType`

The encoding type. This member can be **X509_ASN_ENCODING** or **PKCS_7_ASN_ENCODING**.

### `pbJavaPermissions`

The encoded permission blob.

### `cbJavaPermissions`

The size of the **pbJavaPermissions** buffer, in bytes.

### `pbSigner`

The encoded signer.

### `cbSigner`

The size of the **pbSigner** buffer, in bytes.

### `pwszZone`

The zone index.

### `guidZone`

Reserved.

### `hVerify`

The authenticode policy return code.

## See also

[DownloadJavaEX](https://learn.microsoft.com/windows/desktop/DevNotes/downloadjavaex)

[JAVA_POLICY_PROVIDER](https://learn.microsoft.com/previous-versions/bb432350(v=vs.85))