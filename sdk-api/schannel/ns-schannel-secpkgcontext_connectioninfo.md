# SecPkgContext_ConnectionInfo structure

## Description

The **SecPkgContext_ConnectionInfo** structure contains protocol and cipher information. This structure is used by the
[InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/win32/secauthn/initializesecuritycontext--schannel) function.

This attribute is supported only by the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

## Members

### `dwProtocol`

Protocol used to establish this connection. The following table describes the constants valid for this member.

| Value | Meaning |
| --- | --- |
| **SP_PROT_SSL2_CLIENT**<br><br>8 (0x8) | Secure Sockets Layer 2.0 client-side. Superseded by SP_PROT_TLS1_CLIENT. |
| **SP_PROT_SSL2_SERVER**<br><br>4 (0x4) | Secure Sockets Layer 2.0 server-side. Superseded by SP_PROT_TLS1_SERVER. |
| **SP_PROT_SSL3_CLIENT**<br><br>32 (0x20) | Secure Sockets Layer 3.0 client-side. |
| **SP_PROT_SSL3_SERVER**<br><br>16 (0x10) | Secure Sockets Layer 3.0 server-side. |
| **SP_PROT_TLS1_0_CLIENT**<br><br>128 (0x80) | [Transport Layer Security](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) 1.0 client-side. |
| **SP_PROT_TLS1_0_SERVER**<br><br>64 (0x40) | Transport Layer Security 1.0 server-side. |
| **SP_PROT_TLS1_1_CLIENT**<br><br>512 (0x200) | Transport Layer Security 1.1 client-side. |
| **SP_PROT_TLS1_1_SERVER**<br><br>256 (0x100) | Transport Layer Security 1.1 server-side. |
| **SP_PROT_TLS1_2_CLIENT**<br><br>2048 (0x800) | Transport Layer Security 1.2 client-side. |
| **SP_PROT_TLS1_2_SERVER**<br><br>1024 (0x400) | Transport Layer Security 1.2 server-side. |
| **SP_PROT_TLS1_3_CLIENT**<br><br>8192 (0x2000) | Transport Layer Security 1.3 client-side. |
| **SP_PROT_TLS1_3_SERVER**<br><br>4096 (0x1000) | Transport Layer Security 1.3 server-side. |
| **SP_PROT_DTLS1_0_CLIENT**<br><br>131072 (0x00020000) | Datagram Transport Layer Security 1.0 client-side. |
| **SP_PROT_DTLS1_0_SERVER**<br><br>65536 (0x00010000) | Datagram Transport Layer Security 1.0 server-side. |
| **SP_PROT_DTLS1_2_CLIENT**<br><br>524288 (0x00080000) | Datagram Transport Layer Security 1.2 client-side. |
| **SP_PROT_DTLS1_2_SERVER**<br><br>262144 (0x00040000) | Datagram Transport Layer Security 1.2 server-side. |

### `aiCipher`

Algorithm identifier ([ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)) for the bulk encryption cipher used by this connection. The following table describes the constants valid for this member.

| Value | Meaning |
| --- | --- |
| **CALG_3DES** | 3DES block encryption algorithm |
| **CALG_AES_128** | AES 128-bit encryption algorithm |
| **CALG_AES_256** | AES 256-bit encryption algorithm |
| **CALG_DES** | DES encryption algorithm |
| **CALG_RC2** | RC2 block encryption algorithm |
| **CALG_RC4** | RC4 stream encryption algorithm |
| **0 (Zero)** | No encryption |

### `dwCipherStrength`

Strength of the bulk encryption cipher, in bits. Can be one of the following values: 0, 40, 56, 128, 168, or 256.

### `aiHash`

**ALG_ID** indicating the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) used for generating [Message Authentication Codes](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MACs). The following table describes the constants valid for this member.

| Value | Meaning |
| --- | --- |
| **CALG_MD5** | MD5 hashing algorithm. |
| **CALG_SHA** | SHA hashing algorithm. |

### `dwHashStrength`

Strength of the hash, in bits: 128 or 160.

### `aiExch`

**ALG_ID** indicating the [key exchange algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) used to generate the shared master secret. The following table describes the constants valid for this member.

| Value | Meaning |
| --- | --- |
| **ALG_TYPE_ANY** | Any key exchange algorithm. |
| **CALG_RSA_KEYX** | RSA key exchange. |
| **CALG_DH_EPHEM** | Diffie-Hellman key exchange. |

### `dwExchStrength`

Key length, in bits. For RSA key exchange, this member will typically contain one of the following values: 512, 768, 1024, or 2048. For Diffie-Hellman key exchange, this member will typically contain one of the following values: 224, 256, 384 or 512.