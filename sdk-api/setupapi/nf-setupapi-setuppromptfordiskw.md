# SetupPromptForDiskW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupPromptForDisk** function displays a dialog box that prompts the user for a disk.

## Parameters

### `hwndParent` [in]

Handle to the parent window for this dialog box.

### `DialogTitle` [in]

Optional pointer to a **null**-terminated string specifying the dialog title. If this parameter is **NULL**, the default of ""%s--Files Needed"" (localized) is used. The "%s" is replaced with the text retrieved from the parent window. If no text is retrieved from the parent window, the title is "Files Needed".

### `DiskName` [in]

Optional pointer to a **null**-terminated string specifying the name of the disk to insert. If this parameter is **NULL**, the default "(Unknown)" (localized) is used.

### `PathToSource` [in]

Optional pointer to a **null**-terminated string specifying the path part of the expected location of the file, for example, F:\x86. If not specified, the path where **SetupPromptForDisk** most recently located a file is used. If that list is empty, a system default is used.

### `FileSought` [in]

Pointer to a **null**-terminated string specifying the name of the file needed (filename part only). The filename is displayed if the user clicks on the **Browse** button. This routine looks for the file using its compressed form names; therefore, you can pass cmd.exe and not worry that the file actually exists as cmd.ex_ on the source media.

### `TagFile` [in]

Optional pointer to a **null**-terminated string specifying a tag file (filename part only) that identifies the presence of a particular removable media volume. If the currently selected path would place the file on removable media and a tag file is specified,
**SetupPromptForDisk** looks for the tag file at the root of the drive to determine whether to continue.

For example, if *PathToSource* is A:\x86, the tagfile is disk1.tag, and the user types B:\x86 into the edit control of the prompt dialog box, the routine looks for B:\disk1.tag to determine whether to continue. If the tag file is not found, the function looks for the tagfile using *PathToSource*.

If a tag file is not specified, removable media works just like non-removable media and *FileSought* is looked for before continuing.

### `DiskPromptStyle` [in]

Specifies the behavior of the dialog box. This parameter can be a combination of the following flags.

#### IDF_CHECKFIRST

Check for the file/disk before displaying the prompt dialog box, and, if present, return DPROMPT_SUCCESS immediately.

#### IDF_NOBEEP

Prevent the dialog box from beeping to get the user's attention when it first appears.

#### IDF_NOBROWSE

Do not display the browse option.

#### IDF_NOCOMPRESSED

Do not check for compressed versions of the source file.

#### IDF_NODETAILS

Do not display detail information.

#### IDF_NOFOREGROUND

Prevent the dialog box from becoming the foreground window.

#### IDF_NOSKIP

Do not display the skip option.

#### IDF_OEMDISK

Prompt for a disk supplied by a hardware manufacturer.

#### IDF_WARNIFSKIP

Warn the user that skipping a file may affect the installation.

### `PathBuffer` [in, out]

Optional pointer to a buffer that, upon return, receives the path (no filename) of the location specified by the user through the dialog box. You should use a **null**-terminated string. The **null**-terminated string should not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. See the Remarks section.

### `PathBufferSize` [in]

Size of the buffer pointed to by *PathBuffer*, in characters. It should be at least MAX_PATH long. This includes the **null** terminator.

### `PathRequiredSize` [in, out]

Optional pointer to a variable that receives the required size for *PathBuffer*, in characters. This includes the **null** terminator.

##### - DiskPromptStyle.IDF_CHECKFIRST

Check for the file/disk before displaying the prompt dialog box, and, if present, return DPROMPT_SUCCESS immediately.

##### - DiskPromptStyle.IDF_NOBEEP

Prevent the dialog box from beeping to get the user's attention when it first appears.

##### - DiskPromptStyle.IDF_NOBROWSE

Do not display the browse option.

##### - DiskPromptStyle.IDF_NOCOMPRESSED

Do not check for compressed versions of the source file.

##### - DiskPromptStyle.IDF_NODETAILS

Do not display detail information.

##### - DiskPromptStyle.IDF_NOFOREGROUND

Prevent the dialog box from becoming the foreground window.

##### - DiskPromptStyle.IDF_NOSKIP

Do not display the skip option.

##### - DiskPromptStyle.IDF_OEMDISK

Prompt for a disk supplied by a hardware manufacturer.

##### - DiskPromptStyle.IDF_WARNIFSKIP

Warn the user that skipping a file may affect the installation.

## Return value

The function returns one of the following values.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *PathBuffer* of **NULL** and a *PathBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *PathRequiredSize*. If the function succeeds in this, the return value is NO_ERROR. Otherwise, the return value is one of the values described in the Return Values section.

> [!NOTE]
> The setupapi.h header defines SetupPromptForDisk as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCopyError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcopyerrora)

[SetupDeleteError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdeleteerrora)

[SetupRenameError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuprenameerrora)