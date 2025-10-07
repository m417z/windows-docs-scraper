# SslEnumCipherSuites function

The **SslEnumCipherSuites** function enumerates the cipher suites supported by a [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider.

## Parameters

*hSslProvider* \[in\]

The handle of the SSL protocol provider instance.

*hPrivateKey* \[in, optional\]

The handle of a [*private key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). When a private key is specified, **SslEnumCipherSuites** enumerates the cipher suites that are compatible with the private key. For example, if the private key is a DSS key, then only the DSS\_DHE cipher suites are returned. If the private key is an RSA key, but it does not support raw decryption operations, then the SSL2 cipher suites are not returned.

Set this parameter to **NULL** when you are not specifying a private key.

> [!Note]
> A *hPrivateKey* handle is obtained by calling the [**SslOpenPrivateKey**](https://learn.microsoft.com/windows/win32/seccng/sslopenprivatekey) function. Handles obtained from the [**NCryptOpenKey**](https://learn.microsoft.com/windows/desktop/api/Ncrypt/nf-ncrypt-ncryptopenkey) function are not supported.

*ppCipherSuite* \[out\]

A pointer to a **NCRYPT\_SSL\_CIPHER\_SUITE** structure to receive the address of the next cipher suite in the list.

*ppEnumState* \[in, out\]

A pointer to a buffer that indicates the current position in the list of cipher suites.

Set the pointer to **NULL** on the first call to **SslEnumCipherSuites**. On each subsequent call, pass the unmodified value back to **SslEnumCipherSuites**.

When there are no more cipher suites available, you should free *ppEnumState* by calling the [**SslFreeBuffer**](https://learn.microsoft.com/windows/win32/seccng/sslfreebuffer) function.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **NTE\_NO\_MEMORY**

0x8009000EL | Not enough memory is available to allocate necessary buffers.\ | | **NTE\_INVALID\_HANDLE**

0x80090026L | One of the provided handles is not valid.\ | | **NTE\_NO\_MORE\_ITEMS**

0x8009002AL | No additional cipher suites are supported.\ | ## Remarks To enumerate all cipher suites supported by the SSL provider, call the **SslEnumCipherSuites** function in a loop until **NTE\_NO\_MORE\_ITEMS** is returned. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | Library\ | Ncrypt.lib | | DLL\ | Ncrypt.dll |