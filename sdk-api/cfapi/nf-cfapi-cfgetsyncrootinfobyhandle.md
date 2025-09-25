# CfGetSyncRootInfoByHandle function

## Description

Gets various characteristics of the sync root containing a given file specified by a file handle.

## Parameters

### `FileHandle` [in]

Handle of the file under the sync root whose information is to be queried.

### `InfoClass` [in]

Types of sync root information.

### `InfoBuffer` [out]

A pointer to a buffer that will receive the sync root information.

### `InfoBufferLength` [in]

Length, in bytes, of the *InfoBuffer*.

### `ReturnedLength` [out, optional]

The number of bytes returned in the *InfoBuffer*.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

Unlike most placeholder APIs that take a file handle, this one does not modify the file in any way, therefore the *FileHandle* only requires **READ_ATTRIBUTES** access.

If the file is not underneath a cloud files sync root, the API will fail. On success, information is returned according to the specific *InfoClass* requested.

## See also

[CfGetSyncRootInfoByPath](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetsyncrootinfobypath)