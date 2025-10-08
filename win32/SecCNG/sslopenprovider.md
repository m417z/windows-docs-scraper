# SslOpenProvider function

The **SslOpenProvider** function opens a handle to the specified [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider.

## Parameters

*phSslProvider* \[out\]

The address of an **NCRYPT\_PROV\_HANDLE** in which to write the provider handle.

When you have finished using the handle, you should free it by calling the [**SslFreeObject**](https://learn.microsoft.com/windows/win32/seccng/sslfreeobject) function.

*pszProviderName* \[in\]

A pointer to a Unicode string that contains the provider name. If the value of this parameter is **NULL**, a handle to the **MS\_SCHANNEL\_PROVIDER** is returned.

*dwFlags* \[in\]

This parameter is reserved for future use, and it must be set to zero.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | One of the provided handles is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | The *phSslProvider* or *ppProviderList* parameter is **NULL**.<br> |
| **STATUS\_NO\_MEMORY**<br>0xC0000017L | Not enough memory is available to allocate necessary buffers.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

