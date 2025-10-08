# SslGetKeyProperty function

The **SslGetKeyProperty** function retrieves the value of a named property for a [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) provider key object.

## Parameters

*hKey* \[in\]

The handle of the SSL provider.

*pszProperty* \[in\]

A pointer to a null-terminated Unicode string that contains the name of the property to retrieve. This can be one of the predefined [**Key Storage Property Identifiers**](https://learn.microsoft.com/windows/win32/seccng/key-storage-property-identifiers) or a custom property identifier.

*ppbOutput* \[out\]

A pointer to a buffer that receives the property value. The caller of the function must free this buffer by calling the [**SslFreeBuffer**](https://learn.microsoft.com/windows/win32/seccng/sslfreebuffer) function.

*pcbOutput* \[out\]

The size, in bytes, of the *pbOutput* buffer.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | One of the provided handles is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | One of the supplied parameters is not valid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

