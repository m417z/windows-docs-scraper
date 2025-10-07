# SslFreeBuffer function

The **SslFreeBuffer** function is used to free memory that was allocated by one of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) provider functions.

## Parameters

*pvInput* \[in\]

A pointer to the memory buffer to be freed.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| **NTE\_INVALID\_PARAMETER**

0x80090027L | The *pdwProviderCount* or *ppProviderList* parameter is **NULL**.\ | ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |