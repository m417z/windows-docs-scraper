# IDedupReadFileCallback::ReadBackupFile

## Description

 Reads data from a Data Deduplication store metadata or container file located in the backup store.

## Parameters

### `FileFullPath` [in]

The full path from the root directory of the volume to the container file.

### `FileOffset` [in]

The offset, in bytes, from the beginning of the file to the beginning of the data to be read.

### `SizeToRead` [in]

The number of bytes to read from the file.

### `FileBuffer` [out]

A pointer to a buffer that receives the data that is read from the file. The size of the buffer must be greater than or equal to the number specified in the *SizeToRead* parameter.

### `ReturnedSize` [out]

Pointer to a ULONG variable that receives the number of bytes that were read from the backup store. If the call to **ReadBackupFile** is successful, this number is equal to the value that was specified in the *SizeToRead* parameter.

### `Flags` [in]

This parameter is reserved for future use.

## Return value

This method can return standard **HRESULT** values, such as **S_OK**. It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Possible return values include the following.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[IDedupReadFileCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nn-ddpbackup-idedupreadfilecallback)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)