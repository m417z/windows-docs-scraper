## Description

Imports a PFX certificate.

## Parameters

### `hWndParent` [in]

Handle to a Parent Window.

### `pbPFX` [in]

Pointer to a buffer that contains the PFX file.

### `cbPFX` [in]

Size of pbPFX in bytes.

### `ImportFlags` [in]

One or more [ImportPFXFlag](https://msdn.microsoft.com/en-us/library/Mt832769(v=VS.85).aspx) values.

### `pwszPassword` [in, optional]

Pointer to a constant null-terminated string of 16-bit Unicode characters that is the Password for the PFX file.

### `pwszProviderName` [in, optional]

Pointer to a constant null-terminated string of 16-bit Unicode characters that is the name of the crypto provider.

### `pwszReaderName` [in, optional]

Pointer to a constant null-terminated string of 16-bit Unicode characters that is the name of the smart card reader (can be nullptr).

### `pwszContainerNamePrefix` [in, optional]

Pointer to a constant null-terminated string of 16-bit Unicode characters that is the name of the container (can be nullptr).

### `pwszPin` [in, optional]

Pointer to a constant null-terminated string of 16-bit Unicode characters that is the PIN of the smart card (can be nullptr).

### `pwszFriendlyName` [in, optional]

Pointer to a constant null-terminated string of 16-bit Unicode characters that is the friendly name of the certificate (can be nullptr).

### `pcCertOut` [out, optional]

Pointer to DWORD that receives the number of certificates successfully imported (can be nullptr).

### `prgpCertOut` [out, optional]

Pointer to a pointer that receives a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure (can be nullptr).