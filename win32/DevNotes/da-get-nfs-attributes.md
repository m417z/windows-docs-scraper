# DA\_GET\_NFS\_ATTRIBUTES control code

The **DA\_GET\_NFS\_ATTRIBUTES** control code queries additional information about an NFS share.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL
   WINAPI
   DeviceIoControl( (HANDLE)       hDevice,               // handle to device
                    (DWORD)        DA_GET_NFS_ATTRIBUTES, // dwIoControlCode
                                   NULL,                  // lpInBuffer
                                   0,                     // nInBufferSize
                    (LPDWORD)      lpOutBuffer,           // output buffer
                    (DWORD)        nOutBufferSize,        // size of output buffer
                    (LPDWORD)      lpBytesReturned,       // number of bytes returned
                    (LPOVERLAPPED) lpOverlapped );        // OVERLAPPED structure
```

## Parameters

*hDevice* \[in\]

A handle to a file on the NFS share. To obtain this handle, call the [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function.

*dwIoControlCode* \[in\]

The control code for the operation. Use **DA\_GET\_NFS\_ATTRIBUTES** for this operation.

*lpInBuffer*

Not used with this operation; set to **NULL**.

*nInBufferSize* \[in\]

Not used with this operation; set to zero.

*lpOutBuffer* \[out\]

A pointer to the output buffer, which contains an **NFS\_FILE\_ATTRIBUTES** structure. For more information, see the Remarks section.

*nOutBufferSize* \[in\]

The size of the output buffer, in bytes.

*lpBytesReturned* \[out\]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

If the output buffer is too small, the call fails, [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR\_INSUFFICIENT\_BUFFER**, and *lpBytesReturned* is zero.

If *lpOverlapped* is **NULL**, *lpBytesReturned* cannot be **NULL**. Even when an operation returns no output data and *lpOutBuffer* is **NULL**, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) makes use of *lpBytesReturned*. After such an operation, the value of *lpBytesReturned* is meaningless.

If *lpOverlapped* is not **NULL**, *lpBytesReturned* can be **NULL**. If this parameter is not **NULL** and the operation returns data, *lpBytesReturned* is meaningless until the overlapped operation has completed. To retrieve the number of bytes returned, call [**GetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult). If the *hDevice* parameter is associated with an I/O completion port, you can retrieve the number of bytes returned by calling [**GetQueuedCompletionStatus**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus).

*lpOverlapped* \[in\]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened without specifying **FILE\_FLAG\_OVERLAPPED**, *lpOverlapped* is ignored.

If *hDevice* was opened with the **FILE\_FLAG\_OVERLAPPED** flag, the operation is performed as an overlapped (asynchronous) operation. In this case, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. Otherwise, the function fails in unpredictable ways.

For overlapped operations, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns immediately, and the event object is signaled when the operation has been completed. Otherwise, the function does not return until the operation has been completed or an error occurs.

## Return value

If the operation completes successfully, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This control code has no associated header file. You must define the control code and data structures as follows.

``` syntax
#define DEVICE_DA_RDR 0x80000

#define DA_GET_NFS_ATTRIBUTES CTL_CODE(DEVICE_DA_RDR, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct _NFS_SPEC_DATA {
    ULONG               SpecData1;
    ULONG               SpecData2;
} NFS_SPEC_DATA, *PNFS_SPEC_DATA;

typedef struct _NFS_TIME {
    ULONG        Seconds;
    ULONG        nSeconds;
} NFS_TIME, *PNFS_TIME;

#define NFS_TYPE_REG         1
#define NFS_TYPE_DIR         2
#define NFS_TYPE_BLK         3
#define NFS_TYPE_CHR         4
#define NFS_TYPE_LNK         5
#define NFS_TYPE_SOCK        6
#define NFS_TYPE_FIFO        7

typedef struct _NFS_FILE_ATTRIBUTES {
    ULONG               FileType;
    ULONG               Mode;
    ULONG               NLink;
    ULONG               Uid;
    ULONG               Gid;
    ULONGLONG           Size;
    ULONGLONG           Used;
    NFS_SPEC_DATA       Rdev;
    ULONGLONG           Fsid;
    ULONGLONG           FileId;
    NFS_TIME            AccessTime;
    NFS_TIME            ModifyTime;
    NFS_TIME            ChangeTime;
} NFS_FILE_ATTRIBUTES, *PNFS_FILE_ATTRIBUTES;

typedef struct _DA_FILE_ATTRIBUTES {
    NFS_FILE_ATTRIBUTES FileAttributes;
    ULONG               Version;
} DA_FILE_ATTRIBUTES, *PDA_FILE_ATTRIBUTES;
```

The structure members can be described as follows.

**SpecData1**

An opaque value that is used for special file types such as block-special, character-special and FIFO files.

**SpecData2**

An opaque value that is used for special file types such as block-special, character-special and FIFO files.

**Seconds**

A 64-bit value representing the seconds since January 1, 1970 (UTC).

**nSeconds**

The number of nanoseconds to be added to the **Seconds** member.

**FileType**

The NFS file type of the share.

| NFS File Type | Description |
|--------------------------------------------------------------------------------------------|--------------------------------------|
| NFS\_TYPE\_REG<br> | A regular file.<br> |
| NFS\_TYPE\_DIR<br> | A directory.<br> |
| NFS\_TYPE\_BLK<br> | A block-special file.<br> |
| NFS\_TYPE\_CHR<br> | A character-special file.<br> |
| NFS\_TYPE\_LNK<br> | A symbolic link.<br> |
| NFS\_TYPE\_SOCK<br> | A Windows socket.<br> |
| NFS\_TYPE\_FIFO<br> | A FIFO file.<br> |

**Mode**

The file mode.

**NLink**

The number of links to the share.

**Uid**

The UNIX user identifier (UID).

**Gid**

The UNIX group identifier (GID).

**Size**

The file size, in bytes.

**Used**

The file size used, in bytes. This is the same as the file size.

**Rdev**

The device identifier.

**Fsid**

The file system identifier.

**FileId**

The file identifier.

**AccessTime**

The last access time.

**ModifyTime**

The last modification time.

**ChangeTime**

The last change time.

**FileAttributes**

An **NFS\_FILE\_ATTRIBUTES** structure.

> [!Note]
> For more detailed descriptions of the members of this structure, see the **fattr3** structure in the NFS Version 3 Protocol Specification (as defined in [RFC 1813](https://www.ietf.org/rfc/rfc1813.txt)).

**Version**

Specifies whether the connection on which the handle to the NFS share was created is over NFS Version 2 or NFS Version 3 protocol.

| Value | Description |
|----------------------------------|--------------------------|
| 2<br> | NFS Version 2<br> |
| 3<br> | NFS Version 3<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| End of client support<br> | None supported<br> |
| End of server support<br> | Windows Server 2008 R2<br> |

## See also

[**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)

