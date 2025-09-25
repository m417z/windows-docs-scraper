# CRYPT_TRUST_REG_ENTRY structure

## Description

[The **CRYPT_TRUST_REG_ENTRY** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_TRUST_REG_ENTRY** structure identifies a provider function by DLL name and function name. This structure is used by the [CRYPT_REGISTER_ACTIONID](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_register_actionid) structure when the [WintrustAddActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustaddactionid) function is called.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pwszDLLName`

A pointer to a null-terminated string for the DLL name.

### `pwszFunctionName`

A pointer to a null-terminated string for the function name.

## See also

[CRYPT_REGISTER_ACTIONID](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_register_actionid)

[WintrustAddActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustaddactionid)