# SslDecrementProviderReferenceCount function

The **SslDecrementProviderReferenceCount** function decrements the references to the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) provider.

## Parameters

*hSslProvider* \[in\]

The handle of the SSL protocol provider instance.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------|
| **STATUS\_INVALID\_HANDLE**

0xC0000008L | The SSL provider handle is not valid.\ | ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |