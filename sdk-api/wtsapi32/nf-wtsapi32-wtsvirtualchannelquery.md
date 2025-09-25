# WTSVirtualChannelQuery function

## Description

Returns information about a specified virtual
channel.

## Parameters

### `hChannelHandle` [in]

Handle to a virtual channel opened by the
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen) function.

### `WTS_VIRTUAL_CLASS` [in]

Specifies the type of information returned in the *ppBuffer* parameter. This parameter
can be a value from the [WTS_VIRTUAL_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_virtual_class)
enumeration type.

### `ppBuffer` [out]

Pointer to a buffer that receives the requested information.

### `pBytesReturned` [out]

Pointer to a variable that receives the number of bytes returned in the *ppBuffer*
parameter.

## Return value

If the function succeeds, the return value is a nonzero value. Call the
[WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory) function with the value returned in
the *ppBuffer* parameter to free the temporary memory allocated by
**WTSVirtualChannelQuery**.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following example shows how to gain access to a virtual channel file handle that can be used for
asynchronous I/O. First the code opens a virtual channel by using a call to the
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen) function.
Then the code calls the
**WTSVirtualChannelQuery** function, specifying
the WTSVirtualFileHandle virtual class type.
**WTSVirtualChannelQuery** returns a file
handle that you can use to perform asynchronous (overlapped) read and write operations. Finally, the code frees
the memory allocated by
**WTSVirtualChannelQuery** with a call to the
[WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory) function, and closes the
virtual channel with a call to the
[WTSVirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelclose) function.

Note that you should not explicitly close the file handle obtained by calling
**WTSVirtualChannelQuery**. This is because
[WTSVirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelclose) closes the file handle.

```cpp
    PVOID vcFileHandlePtr = NULL;
    DWORD len;
    DWORD result = ERROR_SUCCESS;
    HANDLE vcHandle = NULL;
    HANDLE vcFileHandle = NULL;

    //
    //  Open a virtual channel.
    //
    vcHandle = WTSVirtualChannelOpen(
                      WTS_CURRENT_SERVER_HANDLE, // Current TS Server
                      WTS_CURRENT_SESSION,       // Current TS Session
                      (LPSTR) "TSTCHNL"                 // Channel name
                      );

    if (vcHandle == NULL)
    {
        result = GetLastError();
    }

    //
    //  Gain access to the underlying file handle for
    //   asynchronous I/O.
    //
    if (result == ERROR_SUCCESS)
    {
        if (!WTSVirtualChannelQuery(
                            vcHandle,
                            WTSVirtualFileHandle,
                            &vcFileHandlePtr,
                            &len
                            ))
        {
            result = GetLastError();
        }
    }

    //
    //  Copy the data and
    //   free the buffer allocated by WTSVirtualChannelQuery.
    //
    if (result == ERROR_SUCCESS)
    {
        memcpy(&vcFileHandle, vcFileHandlePtr, sizeof(vcFileHandle));
        WTSFreeMemory(vcFileHandlePtr);

        //
        //  Use vcFileHandle for overlapped reads and writes here.
        //
        //.
        //.
        //.
    }

    //
    //  Call WTSVirtualChannelClose to close the virtual channel.
    //   Note: do not close the file handle.
    //
    if (vcHandle != NULL)
    {
        WTSVirtualChannelClose(vcHandle);
        vcFileHandle = NULL;
    }

```

For more information about overlapped mode, see
[Synchronization and Overlapped Input and
Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## See also

[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen)

[WTS_VIRTUAL_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_virtual_class)