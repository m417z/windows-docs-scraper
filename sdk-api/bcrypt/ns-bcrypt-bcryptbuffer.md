## Description

Represents a generic Cryptography API: Next Generation (CNG) buffer.

> [!NOTE]
> This struct is also aliased as NCryptBuffer.

## Members

### `cbBuffer`

The size, in bytes, of the buffer.

### `BufferType`

The type of buffer represented by this structure. This can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **KDF_HASH_ALGORITHM** 0 | The buffer is a key derivation function (KDF) parameter that contains a null-terminated Unicode string that identifies the hash algorithm. This can be one of the standard hash algorithm identifiers from [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-identifiers) or the identifier for another registered hash algorithm.<br><br>The size specified by the *cbBuffer* member of this structure must include the terminating NULL character. |
| **KDF_SECRET_PREPEND** 1 | The buffer is a KDF parameter that contains the value to add to the beginning of the message that is input to the hash function. |
| **KDF_SECRET_APPEND** 2 | The buffer is a KDF parameter that contains the value to add to the end of the message that is input to the hash function. |
| **KDF_HMAC_KEY** 3 | The buffer is a KDF parameter that contains the plain text value of the HMAC key. |
| **KDF_TLS_PRF_LABEL** 4 | The buffer is a KDF parameter that contains an ANSI string that contains the [transport layer security](https://learn.microsoft.com/windows/win32/secgloss/t-gly) (TLS) [pseudo-random function](https://learn.microsoft.com/windows/win32/secgloss/p-gly) (PRF) label. |
| **KDF_TLS_PRF_SEED** 5 | The buffer is a KDF parameter that contains the PRF seed value. The seed must be 64 bytes long. |
| **KDF_SECRET_HANDLE** 6 | The buffer is a KDF parameter that contains the secret agreement handle. The *pvBuffer* member contains a **BCRYPT_SECRET_HANDLE** value and is not a pointer. |
| **KDF_TLS_PRF_PROTOCOL** 7 | The buffer is a KDF parameter that contains a DWORD value identifying the SSL/TLS protocol version whose PRF algorithm is to be used. |
| **KDF_ALGORITHMID** 8 | The buffer is a KDF parameter that contains the byte array to use as the **AlgorithmID** subfield of the *OtherInfo* parameter to the SP 800-56A KDF. |
| **KDF_PARTYUINFO** 9 | The buffer is a KDF parameter that contains the byte array to use as the **PartyUInfo** subfield of the *OtherInfo* parameter to the SP 800-56A KDF. |
| **KDF_PARTYVINFO** 10 | The buffer is a KDF parameter that contains the byte array to use as the **PartyVInfo** subfield of the *OtherInfo* parameter to the SP 800-56A KDF. |
| **KDF_SUPPPUBINFO** 11 | The buffer is a KDF parameter that contains the byte array to use as the **SuppPubInfo** subfield of the *OtherInfo* parameter to the SP 800-56A KDF. |
| **KDF_SUPPPRIVINFO** 12 | The buffer is a KDF parameter that contains the byte array to use as the **SuppPrivInfo** subfield of the *OtherInfo* parameter to the SP 800-56A KDF. |
| **KDF_LABEL** 13 | The buffer is a KDF parameter that contains the byte array to use as the *Label* parameter to the SP800-108 HMAC in counter mode KDF. |
| **KDF_CONTEXT** 14 | The buffer is a KDF parameter that contains the byte array to use as the *Context* parameter to the SP800-108 HMAC in counter mode KDF. |
| **KDF_SALT** 15 | The buffer is a KDF parameter that contains the byte array to use as the *Salt* parameter to PBKDF2. |
| **KDF_ITERATION_COUNT** 16 | The buffer is a KDF parameter that contains the **ULONGLONG** to use as the *Iteration Count* parameter to PBKDF2. |
| **KDF_GENERIC_PARAMETER** 17 | The buffer is represents multiple KDF parameters at once. See [BCryptKeyDerivation function](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptkeyderivation) for more info. |
| **KDF_HKDF_INFO** 20 | The buffer is a KDF parameter that contains the byte array to use as the *info* parameter to HKDF. |

### `pvBuffer`

A 32-bit value defined by the *BufferType* member.

## Remarks

## See also

[BCryptKeyDerivation](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptkeyderivation)