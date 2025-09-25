# SetupCopyErrorA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupCopyError** function generates a dialog box to notify a user of a copy file error.

## Parameters

### `hwndParent` [in]

The handle to the parent window for this dialog box.

### `DialogTitle` [in]

An optional pointer to a **null**-terminated string that specifies the dialog box title.

This parameter can be **NULL**. If this parameter is **NULL**, the default title of "Copy Error" (localized to the system language) is used.

### `DiskName` [in]

An optional pointer to a **null**-terminated string that specifies the name of the disk to insert.

This parameter can be **NULL**. If this parameter is **NULL**, the default name "(Unknown)" (localized to the system language) is used.

### `PathToSource` [in]

A pointer to the path component of the source file where an operation fails, for example, F:\x86.

Use a **null**-terminated string.

### `SourceFile` [in]

A pointer to a **null**-terminated string that specifies the filename part of the file where an operation fails.

Use a **null**-terminated string. This filename is displayed if the user clicks on the **Details** or **Browse** buttons. The **SetupCopyError** function looks for the file that uses its compressed form names. Therefore, you can pass cmd.exe and not worry that the file actually exists as cmd.ex_ on the source media.

### `TargetPathFile` [in]

An optional pointer to a **null**-terminated string that specifies the full path of the target file for rename and copy operations.

Use a **null**-terminated string. This parameter can be **NULL**. If TargetPathFile is not specified, "(Unknown)" (localized to the system language) is used.

### `Win32ErrorCode` [out]

If an error occurs, this member is the [System Error Code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

If an error does not occur, it is NO_ERROR.

### `Style` [in]

The flags that control display formatting and behavior of a dialog box.

This parameter can be one of the following flags.

#### IDF_NOBROWSE

Do not display the browse option.

#### IDF_NOSKIP

Do not display the skip file option.

#### IDF_NODETAILS

Do not display the details option.

If this flag is set, the *TargetPathFile* and *Win32ErrorCode* parameters can be omitted.

#### IDF_NOCOMPRESSED

Do not check for compressed versions of the source file.

#### IDF_OEMDISK

The operation source is a disk that a hardware manufacturer provides.

#### IDF_NOBEEP

Prevents the dialog box from beeping to get the user's attention when it first appears.

#### IDF_NOFOREGROUND

Prevents the dialog box from becoming the foreground window.

#### IDF_WARNIFSKIP

Warns the user that skipping a file can affect the installation.

### `PathBuffer` [in, out]

An optional pointer to a variable in which this function returns the path (not including the filename) of the location that a user specifies in the dialog box. You should use a null-terminated string.

The **null**-terminated string should not exceed the size of the destination buffer. To avoid insufficient buffer errors, *PathBuffer* should be at least MAX_PATH.
For more information, see the Remarks section of this topic.

### `PathBufferSize` [in]

 The size of the buffer that *PathBuffer* points to, in characters.

The buffer size should be at least MAX_PATH characters, including the **null** terminator.

### `PathRequiredSize` [in, out]

An optional pointer to a variable in which this function returns the required buffer size, in characters, including the **null** terminator.

## Return value

The function returns one of the following values.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *PathBuffer* of **NULL** and a *PathBufferSize* of 0 (zero), the function puts the buffer size that is needed to hold the specified data into the variable pointed to by *PathRequiredSize*.

If the function succeeds, the return value is NO_ERROR. Otherwise, the return value is one of the specified values.

To avoid insufficient buffer errors, *ReturnBuffer* should be at least MAX_PATH.

> [!NOTE]
> The setupapi.h header defines SetupCopyError as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupDeleteError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdeleteerrora)

[SetupPromptForDisk](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptfordiska)

[SetupRenameError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuprenameerrora)