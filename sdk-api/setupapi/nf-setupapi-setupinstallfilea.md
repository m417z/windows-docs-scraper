# SetupInstallFileA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupInstallFile** function installs a file as specified either by an
[INFCONTEXT](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-infcontext) returned by SetupFindXXXLine or explicitly by the file name and path.

If a file is copied, the caller of this function must have write privileges into the target directory.

## Parameters

### `InfHandle` [in]

Optional pointer to the handle to an INF file that contains SourceDisksNames and SourceDisksFiles sections. If platform-specific sections exist for the user's system (for example, SourceDisksNames.x86 and SourceDisksFiles.x86), the platform-specific section will be used. If *InfContext* is null and *CopyStyle* includes SP_COPY_SOURCE_ABSOLUTE or SP_COPY_SOURCEPATH_ABSOLUTE, *InfHandle* is ignored.

### `InfContext` [in]

Optional pointer to the context of a line in a Copy Files section in an INF file. The routine looks up this file in the SourceDisksFiles section of *InfHandle* to get file copy information. If *InfHandle* is not specified, *SourceFile* must be.

### `SourceFile` [in]

Optional pointer to the file name (no path) of the file to copy. The file is looked up in the SourceDisksFiles section. The *SourceFile* parameter must be specified if *InfContext* is not. *SourceFile* is ignored if *InfContext* is specified.

### `SourcePathRoot` [in]

Optional pointer to the root path for the file to be copied (for example, A:\ or F:\). Paths in the SourceDisksNames section are appended to this path. The *SourcePathRoot* parameter is ignored if *CopyStyle* includes the SP_COPY_SOURCE_ABSOLUTE flag.

### `DestinationName` [in]

Optional pointer to the file name only (no path) of the target file. This parameter can be null to indicate that the target file should have the same name as the source file. If *InfContext* is not specified, *DestinationName* supplies the full path and file name for the target.

### `CopyStyle` [in]

Flags that control the behavior of the file copy operation. These flags may be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SP_COPY_DELETESOURCE** | Deletes the source file upon successful copy. The caller is not notified if the delete operation fails. |
| **SP_COPY_REPLACEONLY** | Copies the file only if doing so would overwrite a file at the destination path. If the target does not exist, the function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns NO_ERROR. |
| **SP_COPY_NEWER_OR_SAME** | Examines each file being copied to see if its version resources indicate that it is either the same version or not newer than an existing copy on the target. <br><br>The file version information used during version checks is that specified in the **dwFileVersionMS** and **dwFileVersionLS** members of a [VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure, as filled in by the version functions. If one of the files does not have version resources, or if they have identical version information, the source file is considered newer.<br><br>If the source file is not newer or equal in version, and *CopyMsgHandler* is specified, the caller is notified and may cancel the copy operation. If *CopyMsgHandler* is not specified, the file is not copied. |
| **SP_COPY_NEWER_ONLY** | Examine each file being copied to see if its version resources indicate that it is not newer than an existing copy on the target. If the source file is newer but not equal in version to the existing target, the file is copied. |
| **SP_COPY_NOOVERWRITE** | Check whether the target file exists, and, if so, notify the caller who may veto the copy. If *CopyMsgHandler* is not specified, the file is not overwritten. |
| **SP_COPY_NODECOMP** | Do not decompress the file. When this flag is set, the target file is not given the uncompressed form of the source name (if appropriate). For example, copying F:*\x86\cmd.ex_* to \\*install*\*temp* results in a target file of *\\install\temp\cmd.ex_*. If the SP_COPY_NODECOMP flag was not specified, the file would be decompressed and the target would be called *\\install\temp\cmd.exe*. The file name part of *DestinationName*, if specified, is stripped and replaced with the file name of the source file. When SP_COPY_NODECOMP is specified, no language or version information can be checked. |
| **SP_COPY_LANGUAGEAWARE** | Examine each file being copied to see if its language differs from the language of any existing file already on the target. If so, and *CopyMsgHandler* is specified, the caller is notified and may cancel the copy. If *CopyMsgHandler* is not specified, the file is not copied. |
| **SP_COPY_SOURCE_ABSOLUTE** | *SourceFile* is a full source path. Do not look it up in the SourceDisksNames section of the INF file. |
| **SP_COPY_SOURCEPATH_ABSOLUTE** | *SourcePathRoot* is the full path part of the source file. Ignore the relative source specified in the SourceDisksNames section of the INF file for the source media where the file is located. This flag is ignored if SP_COPY_SOURCE_ABSOLUTE is specified. |
| **SP_COPY_FORCE_IN_USE** | If the target exists, behaves as if it is in use and queues the file for copying on the next system restart. |
| **SP_COPY_FORCE_NOOVERWRITE** | Checks whether the target file exists, and, if so, the file is not overwritten. The caller is not notified. |
| **SP_COPY_FORCE_NEWER** | Examines each file being copied to see if its version resources (or time stamps for non-image files) indicate that it is not newer than an existing copy on the target. If the file being copied is not newer, the file is not copied. The caller is not notified. The function returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns NO_ERROR. |

### `CopyMsgHandler` [in]

Optional pointer to a callback function to be notified of various conditions that may arise during the file copy operation.

### `Context` [in]

Optional pointer to a caller-defined value that is passed as the first parameter of the callback function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns NO_ERROR, the file copy operation was not completed. The file may not have been copied because the file copy operation was unnecessary or because the file callback function returned **FALSE**.

## Remarks

If a UNC directory is specified as the target directory of a file installation, you must ensure it exists before you call
**SetupInstallFile**. The setup functions do not check for the existence of nor create UNC directories. If the target UNC directory does not exist, the file installation will fail.

> [!NOTE]
> The setupapi.h header defines SetupInstallFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCloseFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupclosefilequeue)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)

[SetupOpenFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenfilequeue)

[SetupQueueCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopya)