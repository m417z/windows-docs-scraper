# SHFileOperationW function

## Description

Copies, moves, renames, or deletes a file system object. This function has been replaced in Windows Vista by [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation).

## Parameters

### `lpFileOp` [in, out]

Type: **LPSHFILEOPSTRUCT**

A pointer to an [SHFILEOPSTRUCT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shfileopstructa) structure that contains information this function needs to carry out the specified operation. This parameter must contain a valid value that is not **NULL**. You are responsible for validating the value. If you do not validate it, you will experience unexpected results.

## Return value

Type: **int**

Returns zero if successful; otherwise nonzero. Applications normally should simply check for zero or nonzero.

It is good practice to examine the value of the **fAnyOperationsAborted** member of the [SHFILEOPSTRUCT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shfileopstructa). **SHFileOperation** can return 0 for success if the user cancels the operation. If you do not check **fAnyOperationsAborted** as well as the return value, you cannot know that the function accomplished the full task you asked of it and you might proceed under incorrect assumptions.

Do not use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) with the return values of this function.

To examine the nonzero values for troubleshooting purposes, they largely map to those defined in Winerror.h. However, several of its possible return values are based on pre-Win32 error codes, which in some cases overlap the later Winerror.h values without matching their meaning. Those particular values are detailed here, and *for these specific values only* these meanings should be accepted over the Winerror.h codes. However, these values are provided with these warnings:

* These are pre-Win32 error codes and are no longer supported or defined in any public header file. To use them, you must either define them yourself or compare against the numerical value.
* These error codes are subject to change and have historically done so.
* These values are provided only as an aid in debugging. They should not be regarded as definitive.

| Error Code | Value | Meaning |
| --- | --- | --- |
| DE_SAMEFILE | 0x71 | The source and destination files are the same file. |
| DE_MANYSRC1DEST | 0x72 | Multiple file paths were specified in the source buffer, but only one destination file path. |
| DE_DIFFDIR | 0x73 | Rename operation was specified but the destination path is a different directory. Use the move operation instead. |
| DE_ROOTDIR | 0x74 | The source is a root directory, which cannot be moved or renamed. |
| DE_OPCANCELLED | 0x75 | The operation was canceled by the user, or silently canceled if the appropriate flags were supplied to **SHFileOperation**. |
| DE_DESTSUBTREE | 0x76 | The destination is a subtree of the source. |
| DE_ACCESSDENIEDSRC | 0x78 | Security settings denied access to the source. |
| DE_PATHTOODEEP | 0x79 | The source or destination path exceeded or would exceed MAX_PATH. |
| DE_MANYDEST | 0x7A | The operation involved multiple destination paths, which can fail in the case of a move operation. |
| DE_INVALIDFILES | 0x7C | The path in the source or destination or both was invalid. |
| DE_DESTSAMETREE | 0x7D | The source and destination have the same parent folder. |
| DE_FLDDESTISFILE | 0x7E | The destination path is an existing file. |
| DE_FILEDESTISFLD | 0x80 | The destination path is an existing folder. |
| DE_FILENAMETOOLONG | 0x81 | The name of the file exceeds MAX_PATH. |
| DE_DEST_IS_CDROM | 0x82 | The destination is a read-only CD-ROM, possibly unformatted. |
| DE_DEST_IS_DVD | 0x83 | The destination is a read-only DVD, possibly unformatted. |
| DE_DEST_IS_CDRECORD | 0x84 | The destination is a writable CD-ROM, possibly unformatted. |
| DE_FILE_TOO_LARGE | 0x85 | The file involved in the operation is too large for the destination media or file system. |
| DE_SRC_IS_CDROM | 0x86 | The source is a read-only CD-ROM, possibly unformatted. |
| DE_SRC_IS_DVD | 0x87 | The source is a read-only DVD, possibly unformatted. |
| DE_SRC_IS_CDRECORD | 0x88 | The source is a writable CD-ROM, possibly unformatted. |
| DE_ERROR_MAX | 0xB7 | MAX_PATH was exceeded during the operation. |
|  | 0x402 | An unknown error occurred. This is typically due to an invalid path in the source or destination. This error does not occur on Windows Vista and later. |
| ERRORONDEST | 0x10000 | An unspecified error occurred on the destination. |
| DE_ROOTDIR \| ERRORONDEST | 0x10074 | Destination is a root directory and cannot be renamed. |

## Remarks

You should use fully qualified path names with this function. Using it with relative path names is not thread safe.

With two exceptions, you cannot use **SHFileOperation** to move special folders from a local drive to a remote computer by specifying a network path. The exceptions are the **My Documents** ([CSIDL_PERSONAL](https://learn.microsoft.com/windows/desktop/shell/csidl), [CSIDL_DOCUMENTS](https://learn.microsoft.com/windows/desktop/shell/csidl)) and **My Pictures** folders ([CSIDL_MYPICTURES](https://learn.microsoft.com/windows/desktop/shell/csidl)).

When used to delete a file, **SHFileOperation** permanently deletes the file unless you set the **FOF_ALLOWUNDO** flag in the **fFlags** member of the [SHFILEOPSTRUCT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shfileopstructa) structure pointed to by *lpFileOp*. Setting that flag sends the file to the Recycle Bin. If you want to simply delete a file and guarantee that it is not placed in the Recycle Bin, use [DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea).

If a copy callback handler is exposed and registered, **SHFileOperation** calls it unless you set a flag such as **FOF_NOCONFIRMATION** in the **fFlags** member of the structure pointed to by *lpFileOp*. See [ICopyHook::CopyCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776048(v=vs.85)) for details on implementing copy callback handlers.

File deletion is recursive unless you set the **FOF_NORECURSION** flag in *lpFileOp*.

### Connecting Files

With Windows 2000 or later, it is possible to *connect* an HTML file with a folder that contains related files such as Graphics Interchange Format (GIF) images or style sheets. If file connection is enabled, when you move or copy the HTML file, the connected folder and all of its files are also moved or copied. Conversely, if you move the folder with the related files, the HTML file is also moved.

The HTML file must have a .htm or .html extension. You create the connection to the related files by placing the folder that contains them into the same folder as the HTML file. The name of the folder that contains the connected files must be the same as the name of the HTML file followed by "_files" or ".files" (this is case sensitive; for example, ".Files" does not work). An example is given here.

1. Create a file named Test.htm in the C:\Files directory (C:\Files\Test.htm).
2. Create a new folder named Test.files in the C:\Files directory (C:\Files\Test.files).
3. Populate the folder with a few files. Any file placed in this folder is connected to Test.htm.
4. Move or copy the Test.htm file to the C:\Files2 directory.
5. Note that the Test.files directory is now found in the C:\Files2 directory as well.

File connection is enabled by default. It can be disabled by adding a **REG_DWORD** entry, NoFileFolderConnection, as shown here:

```
HKEY_CURRENT_USER
   Software
      Microsoft
         Windows
            CurrentVersion
               Explorer
                  NoFileFolderConnection
```

Setting NoFileFolderConnection to 1 disables file connection. If the value is set to zero or is missing, file connection is enabled.

To move only the specified files and none of the connected files, set the **FOF_NO_CONNECTED_ELEMENTS** flag in the **fFlags** member of the structure pointed to by *lpFileOp*.

Note that the use of a folder with a name like "MyFile_files" to define a connection may not be valid for localized versions of Windows. The term "files" may need to be replaced by the equivalent word in the local language.

> [!NOTE]
> The shellapi.h header defines SHFileOperation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).