# SecPkgContext_SupportedSignatures structure

## Description

Specifies the signature algorithms supported by an Schannel connection.

## Members

### `cSignatureAndHashAlgorithms`

The number of elements in the *pSignatureAndHashAlgorithms* array.

### `pSignatureAndHashAlgorithms`

An array of values that specify supported algorithms. These values are in the following format.

The upper byte can be one of the following values that specifies a signature algorithm.

| Value | Meaning |
| --- | --- |
| 0 | Anonymous signature algorithm. |
| 1 | The RSA signature algorithm. |
| 2 | The DSA signature algorithm. |
| 3 | The ECDSA signature algorithm. |
| 255 | Reserved. |

The lower byte can be one of the following values that specifies a hash algorithm.

| Value | Meaning |
| --- | --- |
| 0 | None. |
| 1 | The MD5 hash algorithm. |
| 2 | The SHA1 hash algorithm. |
| 3 | The SHA-224 hash algorithm. |
| 4 | The SHA-256 hash algorithm. |
| 5 | The SHA-384 hash algorithm. |
| 6 | The SHA-512 hash algorithm. |
| 255 | Reserved. |

## See also

[QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw)