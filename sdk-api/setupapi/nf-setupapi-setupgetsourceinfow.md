# SetupGetSourceInfoW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetSourceInfo** function retrieves the path, tag file, or media description for a source listed in an INF file.

## Parameters

### `InfHandle` [in]

Handle to an open INF file that contains a **SourceDisksNames** section. If platform-specific sections exist for the user's system (for example, **SourceDisksNames.x86**), the platform-specific section will be used.

### `SourceId` [in]

Identifier for a source media. This value is used to search by key in the **SourceDisksNames** section.

### `InfoDesired` [in]

Indicates what information is desired. Only one value may be specified per function call, and they cannot be combined. The following types of information can be retrieved from a **SourceDisksNames** section.

#### SRCINFO_PATH

The path specified for the source. This is not a full path, but the path relative to the installation root.

#### SRCINFO_TAGFILE

The tag file that identifies the source media, or if cabinets are used, the name of the cabinet file.

#### SRCINFO_DESCRIPTION

A description for the media.

### `ReturnBuffer` [in, out]

Optional pointer to a buffer to receive the retrieved information. Path returns are guaranteed not to end with \. You should use a **null**-terminated string. The **null**-terminated string should not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. See the Remarks section. Using this technique, you can avoid errors due to an insufficient buffer size. This parameter can be **NULL**.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by *ReturnBuffer*, in characters. This includes the **null** terminator.

### `RequiredSize` [in, out]

Optional pointer to a variable that receives the required size for the buffer specified by *ReturnBuffer*, in characters. This includes the **null** terminator. If *ReturnBuffer* is specified and the actual size needed is larger than the value specified by *ReturnBufferSize*, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

##### - InfoDesired.SRCINFO_DESCRIPTION

A description for the media.

##### - InfoDesired.SRCINFO_PATH

The path specified for the source. This is not a full path, but the path relative to the installation root.

##### - InfoDesired.SRCINFO_TAGFILE

The tag file that identifies the source media, or if cabinets are used, the name of the cabinet file.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

> [!NOTE]
> The setupapi.h header defines SetupGetSourceInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetSourceFileLocation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourcefilelocationa)

[SetupGetSourceFileSize](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourcefilesizea)

[SetupGetTargetPath](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgettargetpatha)