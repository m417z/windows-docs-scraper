# SecPkgContext_KeyingMaterialInfo structure

## Description

The **SecPkgContext_KeyingMaterialInfo** structure contains information about the exportable keying material in a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Members

### `cbLabel`

The length, in bytes, of the disambiguating ASCII label, including NUL terminator.

### `pszLabel`

 A NUL-terminated ASCII string. The NUL terminator will be removed by schannel before mixing in pszLabel.

IANA-registered labels should begin with "EXPORTER" to avoid collisions with existing PRF labels. Labels beginning with "EXPERIMENTAL" may be used without registration.

### `cbContextValue`

### `pbContextValue`

The pointer to the application context. Must be **NULL** if *cbContextValue* is zero.

### `cbKeyingMaterial`

The length, in bytes, of the keying material to be generated. Must be greater than zero.

#### - cbConextValue

The length, in bytes, of the application context. Zero if application context is not provided by the caller.