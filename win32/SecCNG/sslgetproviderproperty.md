# SslGetProviderProperty function

The **SslGetProviderProperty** function retrieves the value of a specified provider property.

## Parameters

*hSslProvider* \[in\]

The handle of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) provider for which to retrieve the property.

*pszProperty* \[in\]

A pointer to a null-terminated Unicode string that contains the name of the property to retrieve.

*ppbOutput* \[out\]

The address of a buffer that receives the property value.

The caller of the function must free this buffer by calling the [**SslFreeBuffer**](https://learn.microsoft.com/windows/win32/seccng/sslfreebuffer) function.

*pcbOutput* \[out\]

The size, in bytes, of the *pbOutput* buffer.

*ppEnumState* \[in, out\]

The address of a **VOID** pointer that receives enumeration state information that is used in subsequent calls to this function. This information only has meaning to the SSL provider and is opaque to the caller. The SSL provider uses this information to determine which item is next in the enumeration. If the variable pointed to by this parameter contains **NULL**, the enumeration is started from the beginning.

The caller of the function must free this memory by calling the [**SslFreeBuffer**](https://learn.microsoft.com/windows/win32/seccng/sslfreebuffer) function.

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
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | One of the supplied parameters is not valid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

