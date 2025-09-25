# WINTRUST_SIGNATURE_SETTINGS structure

## Description

The **WINTRUST_SIGNATURE_SETTINGS** structure can be used to specify the signatures on a file.

## Members

### `cbStruct`

Size, in bytes, of this structure.

### `dwIndex`

Contains the index of the signature to be validated if the **dwFlags** member is set to **WSS_VERIFY_SPECIFIC**.

### `dwFlags`

Flags that can be used to refine behavior. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WSS_VERIFY_SPECIFIC**<br><br>0x00000001 | Set this value if you set the **dwIndex** parameter. |
| **WSS_GET_SECONDARY_SIG_COUNT**<br><br>0x00000002 | Set this value to return the number of secondary signatures found in the **cSecondarySigs** member. |

### `cSecondarySigs`

Contains the number of secondary signatures found if the **dwFlags** member is set to **WSS_GET_SECONDARY_SIG_COUNT**.

### `dwVerifiedSigIndex`

The index used for verification. This member is set on return from Wintrust.

### `pCryptoPolicy`

Pointer to a [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure that contains the policy that a signature must pass to be considered valid.

## See also

[CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para)

[WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust)