# CRYPT_REGISTER_ACTIONID structure

## Description

[The **CRYPT_REGISTER_ACTIONID** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_REGISTER_ACTIONID** structure provides information about the functions of a provider. This structure is used by the [WintrustAddActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustaddactionid) function.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `sInitProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the function that initializes the provider.

### `sObjectProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the object provider function.

### `sSignatureProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the signature provider function.

### `sCertificateProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the certificate provider function.

### `sCertificatePolicyProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the certificate policy provider function.

### `sFinalPolicyProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the final policy provider function.

### `sTestPolicyProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the test policy provider function.

### `sCleanupProvider`

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry) structure that identifies the cleanup provider function.

## See also

[CRYPT_TRUST_REG_ENTRY](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_trust_reg_entry)

[WintrustAddActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustaddactionid)