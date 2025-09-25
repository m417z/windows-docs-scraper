# BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO structure

## Description

The **BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO** structure is used with the [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) functions to contain additional information related to authenticated cipher modes.

## Members

### `cbSize`

The size, in bytes, of this structure. Do not set this field directly. Use the [BCRYPT_INIT_AUTH_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcrypt_init_auth_mode_info) macro instead.

### `dwInfoVersion`

The version number of the structure. The only supported value is **BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION**. Do not set this field directly. Use the [BCRYPT_INIT_AUTH_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcrypt_init_auth_mode_info) macro instead.

### `pbNonce`

A pointer to a buffer that contains a nonce. The Microsoft algorithm providers for [Advanced Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (AES) require a nonce for the Counter with CBC-MAC (CCM) and Galois/Counter Mode (GCM) chaining modes, and will return an error if none is present. If a nonce is not used, this member must be set to **NULL**.

### `cbNonce`

The size, in bytes, of the buffer pointed to by the **pbNonce** member.
If a nonce is not used, this member must be set to zero.

### `pbAuthData`

A pointer to a buffer that contains the authenticated data. This is data that will be included in the [Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MAC) but not encrypted. If there is no authenticated data, this member must be set to **NULL**.

### `cbAuthData`

The size, in bytes, of the buffer pointed to by the **pbAuthData** member. If there is no authenticated data, this member must be set to zero.

### `pbTag`

A pointer to a buffer.

The use of this member depends on the function to which the structure is passed.

| Function | Description |
| --- | --- |
| **[BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt)** | The buffer will receive the authentication tag. |
| **[BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt)** | The buffer contains the authentication tag to be checked against. |

If there is no tag, this member must be set to **NULL**.

### `cbTag`

The size, in bytes, of the **pbTag** buffer. The buffer must be long enough to include the whole authentication tag. Some authentication modes, such as CCM and GCM, support checking against a tag with multiple lengths. To obtain the valid authentication tag lengths use [BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty) to query the **BCRYPT_AUTH_TAG_LENGTH** property. If there is no tag, this member must be set to zero.

### `pbMacContext`

A pointer to a buffer that stores the partially computed MAC between calls to [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) when chaining encryption or decryption.

If the input to encryption or decryption is scattered across multiple buffers, then you must chain calls to the [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) functions. Chaining is indicated by setting the **BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG** flag in the **dwFlags** member.

This buffer must be supplied by the caller and must be at least as large as the maximum length of an authentication tag for the cipher you are using. To get the valid authentication tag lengths, use [BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty) to query the **BCRYPT_AUTH_TAG_LENGTH** property.

If [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) calls are not being chained, this member must be set to **NULL**.

### `cbMacContext`

The size, in bytes, of the buffer pointed to by the **pbMacContext** member. If [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) calls are not being chained, this member must be set to zero.

### `cbAAD`

The length, in bytes, of additional authenticated data (AAD) to be used by the [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) functions. This member is used only when chaining calls.

This member is used only when the **BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG** flag in the **dwFlags** member is set.

On the first call to [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) or [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) you must set this field to zero.

**Note** During the chaining sequence, this member is maintained internally and must not be changed or the value of the computed MAC will be corrupted.

### `cbData`

The length, in bytes, of the payload data that was encrypted or decrypted. This member is used only when chaining calls.

This member is used only when the **BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG** flag in the **dwFlags** member is set.

On the first call to [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) or [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) you must set this field to zero, , either directly or by calling the [BCRYPT_INIT_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcrypt_init_auth_mode_info) macro

**Note** During the chaining sequence, this member is maintained internally and must not be changed or the value of the computed MAC will be corrupted.

### `dwFlags`

This flag is used when chaining [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) or [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) function calls. If calls are not being chained, this member must be set to zero.

| Value | Meaning |
| --- | --- |
| 0x00000000 | For [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt), calculate the authentication tag and place it in the buffer pointed to by the **pbTag** member. <br><br>For [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt), calculate the authentication tag and compare it against the tag passed in to the buffer pointed to by the **pbTag** member. When chaining multiple calls to [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) or **BCryptDecrypt**, this value signals the end of the chain. |
| **BCRYPT_AUTH_MODE_CHAIN_CALLS_FLAG**<br><br>0x00000001 | Indicates that [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) function calls are being chained and that the MAC value will not be computed. On the last call in the chain, clear this value to compute the MAC value for the entire chain. |
| **BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG**<br><br>0x00000002 | Indicates that this **BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO** structure is being used in a sequence of chained [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) or [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) function calls. This flag is set and maintained internally.<br><br>**Note** During the chaining sequence, this flag value is maintained internally and must not be changed or the value of the computed MAC will be corrupted. |

## Remarks

The size of this structure is different between 64-bit and 32-bit operating systems. On 64-bit operating systems, the size is different between 64-bit and 32-bit processes. Instances of this structure must not be shared across threads or passed between processes.