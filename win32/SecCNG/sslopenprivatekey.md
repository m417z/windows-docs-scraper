# SslOpenPrivateKey function

The **SslOpenPrivateKey** function opens a handle to a [*private key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

*hSslProvider* \[in\]

The handle to the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*phPrivateKey* \[out\]

The address of a buffer in which to write the handle to the private key.

When you have finished using the key, you should free *phPrivateKey* by calling the [**SslFreeObject**](https://learn.microsoft.com/windows/win32/seccng/sslfreeobject) function.

*pCertContext* \[in\]

The address of the certificate from which to obtain the private key.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **NTE\_NO\_MEMORY**<br>0x8009000EL | Not enough memory is available to allocate necessary buffers.<br> |
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | The *hSslProvider* handle is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | The *phPrivateKey* or *pCertContext* parameter is **NULL**.<br> |

## Remarks

The private key obtained is part of a [*public/private key pair*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) within a [*certificate*](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This function merely extracts the private key from the certificate specified by the *pCertContext* parameter.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

