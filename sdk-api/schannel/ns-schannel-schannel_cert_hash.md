# SCHANNEL_CERT_HASH structure

## Description

Contains the hash store data for the certificate that Schannel uses.

## Members

### `dwLength`

The size, in bytes, of this structure.

### `dwFlags`

Contains bit flags that control the behavior of Schannel. This member can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **SCH_MACHINE_CERT_HASH**<br><br>0x00000001 | The certificate hash of the computer. |

### `hProv`

Handle to the cryptography provider.

### `ShaHash`

The secure hash algorithm.