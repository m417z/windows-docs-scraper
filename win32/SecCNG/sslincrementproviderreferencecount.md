# SslIncrementProviderReferenceCount function

The **SslIncrementProviderReferenceCount** function increments the reference count to a [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) provider instance.

## Parameters

*hSslProvider* \[in\]

The handle to the SSL protocol provider instance.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------|
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | The *hSslProvider* handle is not valid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

