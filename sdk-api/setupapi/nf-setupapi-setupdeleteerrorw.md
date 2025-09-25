# SetupDeleteErrorW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupDeleteError** function generates a dialog box that informs the user of a delete error.

## Parameters

### `hwndParent` [in]

Handle to the parent window for this dialog box.

### `DialogTitle` [in]

Optional pointer to a **null**-terminated string specifying the error dialog box title. If this parameter is **NULL**, the default title of "Delete Error" (localized) is used.

### `File` [in]

Pointer to a **null**-terminated string specifying the full path of the file on which the delete operation failed.

### `Win32ErrorCode` [out]

The [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) encountered during the file operation.

### `Style` [in]

Flags that control display formatting and behavior of the dialog box. This parameter can be one of the following flags.

#### IDF_NOBEEP

Prevent the dialog box from beeping to get the user's attention when it first appears.

#### IDF_NOFOREGROUND

Prevent the dialog box from becoming the foreground window.

##### - Style.IDF_NOBEEP

Prevent the dialog box from beeping to get the user's attention when it first appears.

##### - Style.IDF_NOFOREGROUND

Prevent the dialog box from becoming the foreground window.

## Return value

This function returns one of the following values.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCopyError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcopyerrora)

[SetupPromptForDisk](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptfordiska)

[SetupRenameError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuprenameerrora)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDeleteError as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).