# IPSEC_AUTH_TYPE enumeration

## Description

The **IPSEC_AUTH_TYPE** enumerated type indicates the type of hash algorithm used in an IPsec SA for data origin
authentication and integrity protection.

## Constants

### `IPSEC_AUTH_MD5:0`

Specifies MD5 hash algorithm.

See [RFC 1321](https://www.ietf.org/rfc/rfc1321.txt) for further information.

### `IPSEC_AUTH_SHA_1`

Specifies SHA 1 hash algorithm.

See NIST, FIPS PUB 180-1 for more information.

### `IPSEC_AUTH_SHA_256`

Specifies SHA 256 hash algorithm.

See NIST, Draft FIPS PUB 180-2 for more information.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IPSEC_AUTH_AES_128`

Specifies 128-bit AES hash algorithm.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IPSEC_AUTH_AES_192`

Specifies 192-bit AES hash algorithm.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IPSEC_AUTH_AES_256`

Specifies 256-bit AES hash algorithm.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IPSEC_AUTH_MAX`

Maximum value for testing purposes.