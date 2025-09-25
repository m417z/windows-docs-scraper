# CRYPT_PROVIDER_FUNCTIONS structure

## Description

[The **CRYPT_PROVIDER_FUNCTIONS** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PROVIDER_FUNCTIONS** structure defines the functions used by a cryptographic service provider (CSP) for WinTrust operations.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pfnAlloc`

A pointer to the memory allocation function.

### `pfnFree`

A pointer to the memory deallocation function.

### `pfnAddStore2Chain`

A pointer to the function that adds a store to the chain.

### `pfnAddSgnr2Chain`

A pointer to the function that adds a signer structure to a message structure in a chain.

### `pfnAddCert2Chain`

A pointer to the function that adds a certificate structure to a signer structure in a chain.

### `pfnAddPrivData2Chain`

A pointer to the function that adds private data to a structure.

### `pfnInitialize`

A pointer to the function that initializes policy data.

### `pfnObjectTrust`

A pointer to the function that builds information for the signer data.

### `pfnSignatureTrust`

A pointer to the function that builds information for the signing certificate.

### `pfnCertificateTrust`

A pointer to the function that builds the chain.

### `pfnFinalPolicy`

A pointer to the function that makes the final call to the policy.

### `pfnCertCheckPolicy`

A pointer to the function that checks each certificate while building a chain.

### `pfnTestFinalPolicy`

A pointer to the function that allows structures to be dumped to a file.

### `psUIpfns`

A pointer to a [CRYPT_PROVUI_FUNCS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provui_funcs) structure.

### `pfnCleanupPolicy`

A pointer to the function that cleans up private data.