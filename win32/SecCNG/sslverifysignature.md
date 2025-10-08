# SslVerifySignature function

The **SslVerifySignature** function verifies the specified signature by using the supplied [*hash*](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) and the [*public key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

*hSslProvider* \[in\]

The handle to the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*hPublicKey* \[in\]

The handle to the public key.

*pbHashValue* \[in\]

A pointer to a buffer that contains the hash to use to verify the signature.

*cbHashValue* \[in\]

The size, in bytes, of the *pbHashValue* buffer.

*pbSignature* \[in\]

A pointer to a buffer that contains the signature to verify.

*cbSignature* \[in\]

The size, in bytes, of the *pbSignature* buffer.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | One of the provided handles is not valid.<br> |

## Remarks

The **SslVerifySignature** function is not currently called by Windows. This function is a required part of the SSL Provider interface and should be fully implemented to ensure forward compatibility.

Current implementations of the server side of the [*Transport Layer Security protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) (TLS) connection call the [**NCryptVerifySignature**](https://learn.microsoft.com/windows/desktop/api/Ncrypt/nf-ncrypt-ncryptverifysignature) function during the client authentication to process the certificate verify message.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

