## Description

Cipher info structure. This is returned by SECPKG_ATTR_CIPHER_INFO ulAttribute from the [QueryContextAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw) (Schannel) function.

## Members

### `dwVersion`

The dw version.

### `dwProtocol`

The dw protocol.

### `dwCipherSuite`

The dw cipher suite.

### `dwBaseCipherSuite`

The dw base cipher suite.

### `dwCipherLen`

The dw cipher length.

### `dwCipherBlockLen`

The dw cipher block length in bytes.

### `dwHashLen`

The dw hash length.

### `dwMinExchangeLen`

The dw min exchange length.

### `dwMaxExchangeLen`

The dw max exchange length.

### `dwKeyType`

The dw key type.

### `szCertificate`

The sz certificate.

### `szCipherSuite`

The sz cipher suite.

### `szCipher`

The sz cipher.

### `szExchange`

The sz exchange.

### `szHash`

The sz hash.