# NCryptStreamUpdate function

## Description

The **NCryptStreamUpdate** function encrypts and decrypts blocks of data.

## Parameters

### `hStream` [in]

Handle to the stream object created by calling [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect) or [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect).

### `pbData` [in]

Pointer to the byte array to be processed.

### `cbData`

Number of bytes in the binary array specified by the *pbData* parameter.

### `fFinal`

A Boolean value that specifies whether the last block of data has been processed.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_DATA** | The content could not be decoded. |
| **NTE_INVALID_HANDLE** | The stream handle pointed to by the *hStream* parameter is not valid. |
| **NTE_NO_MEMORY** | There was insufficient memory available to process the content. |

## Remarks

You must call [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect) or [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect) to open a stream before calling **NCryptStreamUpdate**

Messages can be so large that processing them all at once by storing the entire message in memory can be difficult. It is possible, however, to process large messages by partitioning the data to be processed into manageable blocks.

To do this, use **NCryptStreamUpdate** in a loop that advances through the file block by block. As the streamed message is processed, the resulting output data is passed back to your application by using a callback function that you specify. This is shown by the following example. For more information about the callback function, see [PFNCryptStreamOutputCallback](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nc-ncryptprotect-pfncryptstreamoutputcallback).

**Note** We recommend against using too small of a block size. Small blocks require more calls and therefore more calling overhead. Further, the streaming APIs are optimized for larger blocks. You should experiment to find the best block size for the data you must process.

```cpp
BOOL                        fFinal = FALSE;
PBYTE                       pbBuf = NULL;

// Determine the number of bytes to read.
DWORD cbData = GetFileSize( hFileIn, NULL );

// Call NCryptStreamUpdate while there is data left to read.
while(FALSE == fFinal)
{
    // Read dwBlockSize bytes from the file.
    if(dwBlockSize > 1)
    {
        if( !ReadFile(hFileIn, pbBuf, dwBlockSize, &cbResult, NULL) )
        {
            hr = HRESULT_FROM_WIN32(hr);
            goto CleanUp;
        }
    }

    // Decrement the number of bytes to read by the current amount read.
    cbData -= cbResult;

    // Set fFinal if there are no bytes left to read.
    if (cbData <= 0) fFinal = TRUE;

    // Encrypt (or decrypt) the bytes pointed to by pbBuf
    hr = NCryptStreamUpdate(hStream, pbBuf, cbResult, fFinal);
    if( FAILED(hr) )
    {
        goto CleanUp;
    }
}

CleanUp:
    if( NULL != hStream )
    {
        NCryptStreamClose(hStream);
    }
    if( NULL != hDescriptor )
    {
        NCryptCloseProtectionDescriptor( hDescriptor );
    }
    if(NULL != pbBuf)
    {
        LocalFree(pbBuf);
        pbBuf = NULL;
    }
```

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info)

[NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect)

[NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect)