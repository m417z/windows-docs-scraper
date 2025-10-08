# SslFreeObject function

The **SslFreeObject** function frees a key, hash, or provider object.

## Parameters

*hObject* \[in\]

The handle of the object to free.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------|
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | An internal handle is not valid.<br> |
| **STATUS\_INVALID\_HANDLE**<br>0xC0000008L | The provided handle is not valid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

