# SpQueryCredentialsAttributesFn callback function

## Description

The **SpQueryCredentialsAttributes** function retrieves the attributes for a [credential](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

The **SpQueryCredentialsAttributes** function is the dispatch function for the
[QueryCredentialsAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycredentialsattributesa) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `CredentialHandle` [in]

A handle to the credential to query.

### `CredentialAttribute` [in]

[Attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to query. The following table lists the valid values.

| Value | Meaning |
| --- | --- |
| **SECPKG_CRED_ATTR_NAMES** | The name of the principal associated with the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **SECPKG_ATTR_SUPPORTED_ALGS** | The algorithms supported with a particular credential. |
| **SECPKG_ATTR_CIPHER_STRENGTHS** | The minimum and maximum cipher strength used with a credential. |
| **SECPKG_ATTR_SUPPORTED_PROTOCOLS** | The protocols supported with a particular credential. |

### `Buffer` [out]

Pointer to a buffer that receives the requested attributes. Allocate memory for this buffer using the
[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function, so that caller can free it by calling the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists common reasons for failure and the error codes that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INSUFFICIENT_MEMORY** | Memory allocation failed. |
| **SEC_E_INVALID_HANDLE** | The credential handle is not valid. |

## Remarks

SSP/APs must implement the **SpQueryCredentialsAttributes** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpQueryCredentialsAttributes** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)