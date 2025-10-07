# SslExportKeyingMaterial function

Exports keying material per the [RFC 5705 standard](https://tools.ietf.org/html/rfc5705). This function uses the TLS pseudorandom function to produce a byte buffer of keying material. It takes a reference to the master secret, the disambiguating ASCII label, client and server random values, and optionally the application context data.

## Parameters

*hSslProvider* \[in\]

The handle of the TLS protocol provider instance.

*hMasterKey* \[in\]

The handle of the master key object that will be used to create the keying material to br exported.

*sLabel* \[in\]

a NUL-terminated ASCII label string. Schannel will remove the terminating NUL character before passing it to the pseudorandom function.

*pbRandoms* \[in\]

A pointer to a buffer that contains a concatenation of the *client\_random* and *server\_random* values of the TLS connection.

*cbRandoms* \[in\]

The length, in bytes, of the *pbRandoms* buffer.

*pbContextValue* \[in, optional\]

A pointer to a buffer that contains the application context. If *pbContextValue* is **NULL**, *cbContextValue* must be zero.

*cbContextValue* \[in\]

The length, in bytes, of the *pbContextValue* buffer.

*pbOutput* \[out\]

The address of a buffer that receives the exported keying material. The *cbOutput* parameter contains the size of this buffer. This value cannot be **NULL**.

*cbOutput* \[in\]

The length, in bytes, of the *pbOutput* buffer. Must be greater than zero.

*dwFlags* \[in\]

Not used. Must be set to zero.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | One of the provided handles is not valid.\ | ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows 10 \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2016 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |