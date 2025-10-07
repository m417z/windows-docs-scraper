# SslSignHash function

The **SslSignHash** function signs a [*hash*](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) by using the specified [*private key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The signing process is performed on the server.

## Parameters

*hSslProvider* \[in\]

The handle to the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*hPrivateKey* \[in\]

The handle to the private key to use to sign the hash.

*pbHashValue* \[in\]

A pointer to a buffer that contains the hash to sign.

*cbHashValue* \[in\]

The size, in bytes, of the *pbHashValue* buffer.

*pbSignature* \[out\]

The address of a buffer that receives the signature of the hash. The *cbSignature* parameter contains the size of this buffer. To determine the required sized size of the buffer, set the *pbSignature* parameter to **NULL**. The required size of the buffer will be returned in the *pcbResult* parameter.

*cbSignature* \[in\]

The size, in bytes, of the *pbSignature* buffer.

*pcbResult* \[out\]

A pointer to a value that, upon completion, contains the actual number of bytes written to the *pbSignature* buffer.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | One of the provided handles is not valid.\ | ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |