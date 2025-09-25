# mmioOpen function

## Description

The **mmioOpen** function opens a file for unbuffered or buffered I/O; creates a file; deletes a file; or checks whether a file exists. The file can be a standard file, a memory file, or an element of a custom storage system. The handle returned by [mmioOpen](https://learn.microsoft.com/windows/desktop/Multimedia/opening-a-file-with-mmioopen) is not a standard file handle; do not use it with any file I/O functions other than multimedia file I/O functions.

**Note** This function is deprecated. Applications should call [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) to create or open files.

## Parameters

### `pszFileName`

Pointer to a buffer that contains the name of the file. If no I/O procedure is specified to open the file, the file name determines how the file is opened, as follows:

* If the file name does not contain a plus sign (+), it is assumed to be the name of a standard file (that is, a file whose type is not **HMMIO**).
* If the file name is of the form EXAMPLE.EXT+ABC, the extension EXT is assumed to identify an installed I/O procedure which is called to perform I/O on the file. For more information, see [mmioInstallIOProc](https://learn.microsoft.com/previous-versions/dd757323(v=vs.85)).
* If the file name is **NULL** and no I/O procedure is given, the **adwInfo** member of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure is assumed to be the standard (non-**HMMIO**) file handle of a currently open file.

The file name should not be longer than 128 characters, including the terminating NULL character.

When opening a memory file, set *szFilename* to **NULL**.

### `pmmioinfo`

Pointer to an [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure containing extra parameters used by **mmioOpen**. Unless you are opening a memory file, specifying the size of a buffer for buffered I/O, or specifying an uninstalled I/O procedure to open a file, this parameter should be **NULL**. If this parameter is not **NULL**, all unused members of the **MMIOINFO** structure it references must be set to zero, including the reserved members.

### `fdwOpen`

Flags for the open operation. The MMIO_READ, MMIO_WRITE, and MMIO_READWRITE flags are mutually exclusive – only one should be specified. The MMIO_COMPAT, MMIO_EXCLUSIVE, MMIO_DENYWRITE, MMIO_DENYREAD, and MMIO_DENYNONE flags are file-sharing flags. The following values are defined.

| Value | Meaning |
| --- | --- |
| MMIO_ALLOCBUF | Opens a file for buffered I/O. To allocate a buffer larger or smaller than the default buffer size (8K, defined as MMIO_DEFAULTBUFFER), set the **cchBuffer** member of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure to the desired buffer size. If **cchBuffer** is zero, the default buffer size is used. If you are providing your own I/O buffer, this flag should not be used. |
| MMIO_COMPAT | Opens the file with compatibility mode, allowing any process on a given machine to open the file any number of times. If the file has been opened with any of the other sharing modes, **mmioOpen** fails. |
| MMIO_CREATE | Creates a new file. If the file already exists, it is truncated to zero length. For memory files, this flag indicates the end of the file is initially at the start of the buffer. |
| MMIO_DELETE | Deletes a file. If this flag is specified, *szFilename* should not be **NULL**. The return value is **TRUE** (cast to **HMMIO**) if the file was deleted successfully or **FALSE** otherwise. Do not call the [mmioClose](https://learn.microsoft.com/previous-versions/dd757316(v=vs.85)) function for a file that has been deleted. If this flag is specified, all other flags that open files are ignored. |
| MMIO_DENYNONE | Opens the file without denying other processes read or write access to the file. If the file has been opened in compatibility mode by any other process, **mmioOpen** fails. |
| MMIO_DENYREAD | Opens the file and denies other processes read access to the file. If the file has been opened in compatibility mode or for read access by any other process, **mmioOpen** fails. |
| MMIO_DENYWRITE | Opens the file and denies other processes write access to the file. If the file has been opened in compatibility mode or for write access by any other process, **mmioOpen** fails. |
| MMIO_EXCLUSIVE | Opens the file and denies other processes read and write access to the file. If the file has been opened in any other mode for read or write access, even by the current process, **mmioOpen** fails. |
| MMIO_EXIST | Determines whether the specified file exists and creates a fully qualified file name from the path specified in *szFilename*. The return value is **TRUE** (cast to **HMMIO**) if the qualification was successful and the file exists or **FALSE** otherwise. The file is not opened, and the function does not return a valid multimedia file I/O file handle, so do not attempt to close the file.<br><br>**Note** Applications should call **GetFileAttributes** or **GetFileAttributesEx** instead. |
| MMIO_GETTEMP | Creates a temporary file name, optionally using the parameters passed in *szFilename.* For example, you can specify "C:F" to create a temporary file residing on drive C, starting with letter "F". The resulting file name is copied to the buffer pointed to by *szFilename*. The buffer must be large enough to hold at least 128 characters.<br><br>If the temporary file name was created successfully, the return value is **MMSYSERR_NOERROR** (cast to **HMMIO**). Otherwise, the return value is **MMIOERR_FILENOTFOUND** otherwise. The file is not opened, and the function does not return a valid multimedia file I/O file handle, so do not attempt to close the file. This flag overrides all other flags.<br><br>**Note** Applications should call **GetTempFileName** instead. |
| MMIO_PARSE | Creates a fully qualified file name from the path specified in *szFilename*. The fully qualified name is copied to the buffer pointed to by *szFilename*. The buffer must be large enough to hold at least 128 characters.<br><br> If the function succeeds, the return value is **TRUE** (cast to **HMMIO**). Otherwise, the return value is **FALSE**. The file is not opened, and the function does not return a valid multimedia file I/O file handle, so do not attempt to close the file. If this flag is specified, all flags that open files are ignored.<br><br>**Note** Applications should call **GetFullPathName** instead. |
| MMIO_READ | Opens the file for reading only. This is the default if MMIO_WRITE and MMIO_READWRITE are not specified. |
| MMIO_READWRITE | Opens the file for reading and writing. |
| MMIO_WRITE | Opens the file for writing only. |

## Return value

Returns a handle of the opened file. If the file cannot be opened, the return value is **NULL**. If *lpmmioinfo* is not **NULL**, the **wErrorRet** member of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure will contain one of the following error values.

| Return code | Description |
| --- | --- |
| **MMIOERR_ACCESSDENIED** | The file is protected and cannot be opened. |
| **MMIOERR_INVALIDFILE** | Another failure condition occurred. This is the default error for an open-file failure. |
| **MMIOERR_NETWORKERROR** | The network is not responding to the request to open a remote file. |
| **MMIOERR_PATHNOTFOUND** | The directory specification is incorrect. |
| **MMIOERR_SHARINGVIOLATION** | The file is being used by another application and is unavailable. |
| **MMIOERR_TOOMANYOPENFILES** | The number of files simultaneously open is at a maximum level. The system has run out of available file handles. |

## Remarks

If *lpmmioinfo* points to an [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure, initialize the members of the structure as follows. All unused members must be set to zero, including reserved members.

* To request that a file be opened with an installed I/O procedure, set **fccIOProc** to the four-character code of the I/O procedure, and set **pIOProc** to **NULL**.
* To request that a file be opened with an uninstalled I/O procedure, set [IOProc](https://learn.microsoft.com/previous-versions/dd757098(v=vs.85)) to point to the I/O procedure, and set **fccIOProc** to **NULL**.
* To request that **mmioOpen** determine which I/O procedure to use to open the file based on the file name contained in *szFilename*, set **fccIOProc** and **pIOProc** to **NULL**. This is the default behavior if no [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure is specified.
* To open a memory file using an internally allocated and managed buffer, set **pchBuffer** to **NULL**, **fccIOProc** to FOURCC_MEM, **cchBuffer** to the initial size of the buffer, and **adwInfo** to the incremental expansion size of the buffer. This memory file will automatically be expanded in increments of the number of bytes specified in **adwInfo** when necessary. Specify the MMIO_CREATE flag for the *dwOpenFlags* parameter to initially set the end of the file to be the beginning of the buffer.
* To open a memory file using an application-supplied buffer, set **pchBuffer** to point to the memory buffer, **fccIOProc** to FOURCC_MEM, **cchBuffer** to the size of the buffer, and **adwInfo** to the incremental expansion size of the buffer. The expansion size in **adwInfo** should be nonzero only if **pchBuffer** is a pointer obtained by calling the [GlobalAlloc](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalalloc) and [GlobalLock](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globallock) functions; in this case, the [GlobalReAlloc](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalrealloc) function will be called to expand the buffer. In other words, if **pchBuffer** points to a local or global array or a block of memory in the local heap, **adwInfo** must be zero. Specify the MMIO_CREATE flag for the *dwOpenFlags* parameter to initially set the end of the file to be the beginning of the buffer. Otherwise, the entire block of memory is considered readable.
* To use a currently open standard file handle (that is, a file handle that does not have the **HMMIO** type) with multimedia file I/O services, set **fccIOProc** to FOURCC_DOS, **pchBuffer** to **NULL**, and **adwInfo** to the standard file handle. Offsets within the file will be relative to the beginning of the file and are not related to the position in the standard file at the time **mmioOpen** is called; the initial multimedia file I/O offset will be the same as the offset in the standard file when **mmioOpen** is called. To close the multimedia file I/O file handle without closing the standard file handle, pass the MMIO_FHOPEN flag to [mmioClose](https://learn.microsoft.com/previous-versions/dd757316(v=vs.85)).

You must call [mmioClose](https://learn.microsoft.com/previous-versions/dd757316(v=vs.85)) to close a file opened by using **mmioOpen**. Open files are not automatically closed when an application exits.