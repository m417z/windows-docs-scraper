# SHFILEOPSTRUCTA structure

## Description

Contains information that the [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) function uses to perform file operations.

**Note** As of Windows Vista, the use of the [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) interface is recommended over this function.

## Members

### `hwnd`

Type: **HWND**

A window handle to the dialog box to display information about the status of the file operation.

### `wFunc`

Type: **UINT**

A value that indicates which operation to perform. One of the following values:

#### FO_COPY

Copy the files specified in the **pFrom** member to the location specified in the **pTo** member.

#### FO_DELETE

Delete the files specified in **pFrom**.

#### FO_MOVE

Move the files specified in **pFrom** to the location specified in **pTo**.

#### FO_RENAME

Rename the file specified in **pFrom**. You cannot use this flag to rename multiple files with a single function call. Use **FO_MOVE** instead.

### `pFrom`

Type: **PCZZTSTR**

**Note** This string must be double-null terminated.

A pointer to one or more source file names. These names should be fully qualified paths to prevent unexpected results.

Standard MS-DOS wildcard characters, such as "*", are permitted *only* in the file-name position. Using a wildcard character elsewhere in the string will lead to unpredictable results.

Although this member is declared as a single null-terminated string, it is actually a buffer that can hold multiple null-delimited file names. Each file name is terminated by a single **NULL** character. The last file name is terminated with a double **NULL** character ("\0\0") to indicate the end of the buffer.

### `pTo`

Type: **PCZZTSTR**

**Note** This string must be double-null terminated.

A pointer to the destination file or directory name. This parameter must be set to **NULL** if it is not used. Wildcard characters are not allowed. Their use will lead to unpredictable results.

Like **pFrom**, the **pTo** member is also a double-null terminated string and is handled in much the same way. However, **pTo** must meet the following specifications:

* Wildcard characters are not supported.
* Copy and Move operations can specify destination directories that do not exist. In those cases, the system attempts to create them and normally displays a dialog box to ask the user if they want to create the new directory. To suppress this dialog box and have the directories created silently, set the **FOF_NOCONFIRMMKDIR** flag in **fFlags**.
* For Copy and Move operations, the buffer can contain multiple destination file names if the **fFlags** member specifies **FOF_MULTIDESTFILES**.
* Pack multiple names into the **pTo** string in the same way as for **pFrom**.
* Use fully qualified paths. Using relative paths is not prohibited, but can have unpredictable results.

### `fFlags`

Type: **FILEOP_FLAGS**

Flags that control the file operation. This member can take a combination of the following flags.

#### FOF_ALLOWUNDO

Preserve undo information, if possible.

Prior to Windows Vista, operations could be undone only from the same process that performed the original operation.

In Windows Vista and later systems, the scope of the undo is a user session. Any process running in the user session can undo another operation. The undo state is held in the Explorer.exe process, and as long as that process is running, it can coordinate the undo functions.

If the source file parameter does not contain fully qualified path and file names, this flag is ignored.

#### FOF_CONFIRMMOUSE

Not used.

#### FOF_FILESONLY

Perform the operation only on files (not on folders) if a wildcard file name (*.*) is specified.

#### FOF_MULTIDESTFILES

The **pTo** member specifies multiple destination files (one for each source file in **pFrom**) rather than one directory where all source files are to be deposited.

#### FOF_NOCONFIRMATION

Respond with **Yes to All** for any dialog box that is displayed.

#### FOF_NOCONFIRMMKDIR

Do not ask the user to confirm the creation of a new directory if the operation requires one to be created.

#### FOF_NO_CONNECTED_ELEMENTS

[Version 5.0.](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) Do not move connected files as a group. Only move the specified files.

#### FOF_NOCOPYSECURITYATTRIBS

[Version 4.71.](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) Do not copy the security attributes of the file. The destination file receives the security attributes of its new folder.

#### FOF_NOERRORUI

Do not display a dialog to the user if an error occurs.

#### FOF_NORECURSEREPARSE

Not used.

#### FOF_NORECURSION

Only perform the operation in the local directory. Do not operate recursively into subdirectories, which is the default behavior.

#### FOF_NO_UI

[Windows Vista](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Perform the operation silently, presenting no UI to the user. This is equivalent to FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR.

#### FOF_RENAMEONCOLLISION

Give the file being operated on a new name in a move, copy, or rename operation if a file with the target name already exists at the destination.

#### FOF_SILENT

Do not display a progress dialog box.

#### FOF_SIMPLEPROGRESS

Display a progress dialog box but do not show individual file names as they are operated on.

#### FOF_WANTMAPPINGHANDLE

If **FOF_RENAMEONCOLLISION** is specified and any files were renamed, assign a name mapping object that contains their old and new names to the **hNameMappings** member. This object must be freed using [SHFreeNameMappings](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfreenamemappings) when it is no longer needed.

#### FOF_WANTNUKEWARNING

[Version 5.0.](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) Send a warning if a file is being permanently destroyed during a delete operation rather than recycled. This flag partially overrides **FOF_NOCONFIRMATION**.

### `fAnyOperationsAborted`

Type: **BOOL**

When the function returns, this member contains **TRUE** if any file operations were aborted before they were completed; otherwise, **FALSE**. An operation can be manually aborted by the user through UI or it can be silently aborted by the system if the FOF_NOERRORUI or FOF_NOCONFIRMATION flags were set.

### `hNameMappings`

Type: **LPVOID**

When the function returns, this member contains a handle to a name mapping object that contains the old and new names of the renamed files. This member is used only if the **fFlags** member includes the **FOF_WANTMAPPINGHANDLE** flag. See Remarks for more details.

### `lpszProgressTitle`

Type: **PCTSTR**

A pointer to the title of a progress dialog box. This is a null-terminated string. This member is used only if **fFlags** includes the **FOF_SIMPLEPROGRESS** flag.

## Remarks

**Important** You must ensure that the source and destination paths are double-null terminated. A normal string ends in just a single null character. If you pass that value in either the source or destination members, the function will not realize when it has reached the end of the string and will continue to read on in memory until it comes to a random double null value. This can at least lead to a buffer overrun, and possibly the unintended deletion of unrelated data.

```cpp
// WRONG
LPTSTR pszSource = L"C:\\Windows\\*";

// RIGHT
LPTSTR pszSource = L"C:\\Windows\\*\0";

```

To account for the two terminating null characters, be sure to create buffers large enough to hold MAX_PATH (which normally includes the single terminating null character) plus 1.

It cannot be overstated that your paths should always be full paths. If the **pFrom** or **pTo** members are unqualified names, the current directories are taken from the global current drive and directory settings as managed by the [GetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrentdirectory) and [SetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcurrentdirectory) functions.

If you do not provide a full path, the following facts become pertinent:

* The lack of a path before a file name does not indicate to [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) that this file resides in the root of the current directory.
* The PATH environment variable is not used by [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) to determine a valid path.
* [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) cannot be relied on to use the directory that is the current directory when it begins executing. The directory seen as the current directory is process-wide, and it can be changed from another thread while the operation is executing. If that were to happen, the results of **SHFileOperation** would be unpredictable.

If **pFrom** is set to a file name without a full path, deleting the file with **FO_DELETE** does not move it to the Recycle Bin, even if the **FOF_ALLOWUNDO** flag is set. You must provide a full path to delete the file to the Recycle Bin.

[SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) fails on any path prefixed with "\\?\".

There are two versions of this structure, an ANSI version (SHFILEOPSTRUCTA) and a Unicode version (SHFILEOPSTRUCTW). The Unicode version is identical to the ANSI version, except that wide character strings (**LPCWSTR**) are used in place of ANSI character strings (**LPCSTR**). On Windows 98 and earlier, only the ANSI version is supported. On Microsoft Windows NT 4.0 and later, both the ANSI and Unicode versions of this structure are supported. SHFILEOPSTRUCTW and SHFILEOPTSTRUCTA should never be used directly; the appropriate structure is redefined as **SHFILEOPSTRUCT** by the precompiler depending on whether the application is compiled for ANSI or Unicode.

[SHNAMEMAPPING](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shnamemappinga) has similar ANSI and Unicode versions. For ANSI applications, **hNameMappings** points to an **int** followed by an array of ANSI **SHNAMEMAPPING** structures. For Unicode applications, **hNameMappings** points to an **int** followed by an array of Unicode **SHNAMEMAPPING** structures. However, on Microsoft Windows NT 4.0 and later, [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) *always* returns a handle to a Unicode set of **SHNAMEMAPPING** structures. If you want applications to be functional with all versions of Windows, the application must employ conditional code to deal with name mappings. For example:

```cpp
x = SHFileOperation(&shop);

if (fWin9x)
    HandleAnsiNameMappings(shop.hNameMappings);
else
    HandleUnicodeNameMappings(shop.hNameMappings);

```

Treat **hNameMappings** as a pointer to a structure whose members are a **UINT** value followed by a pointer to an array of [SHNAMEMAPPING](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shnamemappinga) structures, as seen in its declaration:

```cpp
struct HANDLETOMAPPINGS
{
    UINT              uNumberOfMappings;  // Number of mappings in the array.
    LPSHNAMEMAPPING   lpSHNameMapping;    // Pointer to the array of mappings.
};

```

The **UINT** value indicates the number of [SHNAMEMAPPING](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shnamemappinga) structures in the array. Each **SHNAMEMAPPING** structure contains the old and new path for one of the renamed files.

**Note** The handle must be freed with [SHFreeNameMappings](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfreenamemappings).

> [!NOTE]
> The shellapi.h header defines SHFILEOPSTRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).