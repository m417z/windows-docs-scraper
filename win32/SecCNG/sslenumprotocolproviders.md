# SslEnumProtocolProviders function

The **SslEnumProtocolProviders** function returns an array of installed [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol providers.

## Parameters

*pdwProviderCount* \[out\]

A pointer to a **DWORD** value to receive the number of protocol providers returned.

*ppProviderList* \[out\]

A pointer to a buffer that receives the array of [**NCryptProviderName**](https://learn.microsoft.com/windows/desktop/api/Ncrypt/ns-ncrypt-ncryptprovidername) structures.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| **NTE\_BAD\_FLAGS**

0x80090009L | The *dwFlags* parameter is not zero.\ | | **NTE\_NO\_MEMORY**

0x8009000EL | Not enough memory is available to allocate necessary buffers.\ | | **NTE\_INVALID\_PARAMETER**

0x80090027L | The *pdwProviderCount* or *ppProviderList* parameter is **NULL**.\ | ## Remarks When you have finished using the array of [**NCryptProviderName**](https://learn.microsoft.com/windows/desktop/api/Ncrypt/ns-ncrypt-ncryptprovidername) structures, call the [**SslFreeBuffer**](https://learn.microsoft.com/windows/win32/seccng/sslfreebuffer) function to free the array. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |