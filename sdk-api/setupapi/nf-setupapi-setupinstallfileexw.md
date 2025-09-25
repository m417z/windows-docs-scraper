# SetupInstallFileExW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupInstallFileEx** function installs a file as specified either by an
[INFCONTEXT](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-infcontext) returned by SetupFindXXXLine or explicitly by the filename and path information. This function is the same as
[SetupInstallFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfilea), except that a **BOOL** is returned that indicates whether the file was in use.

If a file is copied, the caller of this function is required to have privileges to write into the target directory.

## Parameters

### `InfHandle` [in]

Optional pointer to the handle to an INF file that contains the SourceDisksNames and SourceDisksFiles sections. If platform-specific sections exist for the user's system (for example, SourceDisksNames.x86 and SourceDisksFiles.x86), the platform-specific section are used. If *InfContext* is not specified and *CopyStyle* includes SP_COPY_SOURCE_ABSOLUTE or SP_COPY_SOURCEPATH_ABSOLUTE, *InfHandle* is ignored.

### `InfContext` [in]

Optional pointer to context for a line in a Copy Files section in an INF file. The routine looks this file up in the SourceDisksFiles section of *InfHandle* to get file copy information. If *InfContext* is not specified, *SourceFile* must be.

### `SourceFile` [in]

Optional pointer to the filename (no path) of the file to copy. The file is looked up in the SourceDisksFiles section. The *SourceFile* parameter must be specified if *InfContext* is not. However, *SourceFile* is ignored if *InfContext* is specified.

### `SourcePathRoot` [in]

Optional pointer to the root path for the file to be copied (for example, A:\ or F:\). Paths in the SourceDisksNames section are appended to this path. The *SourcePathRoot* parameter is ignored if *CopyStyle* includes the SP_COPY_SOURCE_ABSOLUTE flag.

### `DestinationName` [in]

Optional pointer to a new name for the copied file. If *InfContext* is specified, *DestinationName* supplies the filename only (no path) of the target file. This parameter can be **NULL** to indicate that the target file should have the same name as the source file. If *InfContext* is not specified, *DestinationName* supplies the full target path and filename for the target.

### `CopyStyle` [in]

Flags that control the behavior of the file copy operation.

These flags can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SP_COPY_DELETESOURCE** | Delete the source file upon successful copy. The caller is not notified if the delete fails. |
| **SP_COPY_REPLACEONLY** | Copy the file only if doing so overwrites a file at the destination path. |
| **SP_COPY_NEWER_OR_SAME** | Examine each file being copied to see if its version resources indicate that it is either the same version or not newer than an existing copy on the target. <br><br>The file version information used during version checks is that specified in the **dwFileVersionMS** and **dwFileVersionLS** members of a [VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure, as filled in by the version functions. If one of the files does not have version resources, or if they have identical version information, the source file is considered newer.<br><br>If the source file is not newer or equal in version, and *CopyMsgHandler* is specified, the caller is notified and may cancel the copy. If *CopyMsgHandler* is not specified, the file is not copied. |
| **SP_COPY_NEWER_ONLY** | Examine each file being copied to see if its version resources indicate that it is not newer than an existing copy on the target. If the source file is newer but not equal in version to the existing target, the file is copied. |
| **SP_COPY_NOOVERWRITE** | Check whether the target file exists, and if so, notify the caller who may veto the copy. If *CopyMsgHandler* is not specified, the file is not overwritten. |
| **SP_COPY_NODECOMP** | Do not decompress the file. When this flag is set, the target file is not given the uncompressed form of the source name (if appropriate). For example, copying "f:\x86\cmd.ex_" to "\\install\temp" results in a target file of "\\install\temp\cmd.ex_". If the SP_COPY_NODECOMP flag was not specified, the file would be decompressed and the target would be called "\\install\temp\cmd.exe". The filename part of *DestinationName*, if specified, is stripped and replaced with the filename of the source file. When SP_COPY_NODECOMP is specified, no language or version information can be checked. |
| **SP_COPY_LANGUAGEAWARE** | Examine each file being copied to see if its language differs from the language of any existing file already on the target. If so, and *CopyMsgHandler* is specified, the caller is notified and may cancel the copy. If *CopyMsgHandler* is not specified, the file is not copied. |
| **SP_COPY_SOURCE_ABSOLUTE** | *SourceFile* is a full source path. Do not look it up in the SourceDisksNames section of the INF file. |
| **SP_COPY_SOURCEPATH_ABSOLUTE** | *SourcePathRoot* is the full path part of the source file. Ignore the relative source specified in the SourceDisksNames section of the INF file for the source media where the file is located. This flag is ignored if SP_COPY_SOURCE_ABSOLUTE is specified. |
| **SP_COPY_FORCE_IN_USE** | If the target exists, behave as if it is in use and queue the file for copying on the next system reboot. |
| **SP_COPY_IN_USE_NEEDS_REBOOT** | If the file was in use during the copy operation, alert the user that the system requires a reboot. |
| **SP_COPY_NOSKIP** | Do not give the user the option to skip a file. |
| **SP_COPY_FORCE_NOOVERWRITE** | Check whether the target file exists, and if so, the file is not overwritten. The caller is not notified. |
| **SP_COPY_FORCE_NEWER** | Examine each file being copied to see if its version resources (or time stamps for non-image files) indicate that it is not newer than an existing copy on the target. If the file being copied is not newer, the file is not copied. The caller is not notified. |
| **SP_COPY_WARNIFSKIP** | If the user tries to skip a file, warn them that skipping a file may affect the installation. (Used for system-critical files.) |

### `CopyMsgHandler` [in]

Optional pointer to a callback function to be notified of various conditions that may arise during the file copy.

### `Context` [in]

Pointer to a caller-defined value that is passed as the first parameter of the callback function.

### `FileWasInUse` [out]

Pointer to a variable in which this function returns a flag that indicates whether the file was in use. This parameter is required.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns NO_ERROR, the file copy operation was not completed. The file may not have been copied because the file copy operation was unnecessary or because the file callback function returned **FALSE**.

## Remarks

This API is typically used when installing new versions of system files that are likely to be in use. It updates a **BOOL** value that indicates whether the file was in use. If the file was in use, then the file copy operation is postponed until the system is rebooted.

If a UNC directory is specified as the target directory of a file installation, you must ensure it exists before you call
**SetupInstallFileEx**. The setup functions do not check for the existence of and do not create UNC directories. If the target UNC directory does not exist, the file installation fails.

> [!NOTE]
> The setupapi.h header defines SetupInstallFileEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCloseFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupclosefilequeue)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)

[SetupInstallFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfilea)

[SetupOpenFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenfilequeue)

[SetupPromptReboot](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptreboot)

[SetupQueueCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopya)