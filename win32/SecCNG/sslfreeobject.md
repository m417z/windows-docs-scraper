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
| **NTE\_INVALID\_HANDLE**

0x80090026L | An internal handle is not valid.\ | | **STATUS\_INVALID\_HANDLE**

0xC0000008L | The provided handle is not valid.\ | ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |