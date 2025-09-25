# NCryptStreamOpenToUnprotectEx function

## Description

Opens a stream object that can be used to decrypt large amounts of data to the same protection descriptor used for encryption.Call [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) to perform the decryption. To decrypt smaller messages such as keys and passwords, call [NCryptUnprotectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptunprotectsecret).

## Parameters

### `pStreamInfo` [in]

A pointer to NCRYPT_PROTECT_STREAM_INFO_EX.

### `dwFlags`

Only the NCRYPT_SILENT_FLAG is supported.

### `hWnd` [in, optional]

A window handle to be used as the parent of any user
interface that is displayed.

### `phStream` [out]

Receives a pointer to a stream handle.

## Return value

Returns a status code that indicates the success or failure of the function.
Possible return codes include, but are not limited to:

* ERROR_SUCCESS
* NTE_INVALID_PARAMETER
* NTE_BAD_FLAGS
* NTE_BAD_DATA
* NTE_NO_MEMORY
* NTE_NOT_FOUND
* NTE_NOT_SUPPORTED
* NTE_INVALID_HANDLE
* NTE_BAD_KEY
* NTE_BAD_PROVIDER
* NTE_BAD_TYPE
* NTE_DECRYPTION_FAILURE