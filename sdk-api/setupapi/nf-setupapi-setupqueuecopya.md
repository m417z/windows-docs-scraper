# SetupQueueCopyA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueueCopy** function adds a single file copy operation to a setup file queue.

## Parameters

### `QueueHandle` [in]

Handle to a setup file queue, as returned by
[SetupOpenFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenfilequeue).

### `SourceRootPath` [in]

Pointer to a **null**-terminated string that specifies the root of the source for this copy, such as A:\.

### `SourcePath` [in]

Pointer to a **null**-terminated string that specifies the path relative to *SourceRootPath* where the file can be found. This parameter may be **NULL**.

### `SourceFilename` [in]

Pointer to a **null**-terminated string that specifies the file name part of the file to be copied.

### `SourceDescription` [in]

Pointer to a **null**-terminated string that specifies a description of the source media to be used during disk prompts. This parameter can be **NULL**.

### `SourceTagfile` [in]

Pointer to a **null**-terminated string that specifies a tag file whose presence at *SourceRootPath* indicates the presence of the source media. This parameter may be **NULL**. If not specified, the file itself will be used as the tag file if required.

### `TargetDirectory` [in]

Pointer to a **null**-terminated string that specifies the directory where the file is to be copied.

### `TargetFilename` [in]

Pointer to a **null**-terminated string that specifies the name of the target file. This parameter may be **NULL**. If not specified, the target file will have the same name as the source file.

### `CopyStyle` [in]

Specifies the behavior of the file copy operation. This parameter may be a combination of the following values.

#### SP_COPY_DELETESOURCE

Delete the source file upon successful copy. The caller is not notified if the delete fails.

#### SP_COPY_REPLACEONLY

Copy the file only if doing so would overwrite a file at the destination path. The caller is not notified.

#### SP_COPY_NEWER_OR SAME

Examine each file being copied to see if its version resources indicate that it is either the same version or not newer than an existing copy on the target.

The file version information used during version checks is that specified in the **dwFileVersionMS** and **dwFileVersionLS** members of a
[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure, as filled in by the version functions. If one of the files does not have version resources, or if they have identical version information, the source file is considered newer.

If the source file is not equal in version or newer, and *CopyMsgHandler* is specified, the caller is notified and may cancel the copy. If *CopyMsgHandler* is not specified, the file is not copied.

#### SP_COPY_NEWER_ONLY

Examine each file being copied to see if its version resources indicate that it is not newer than an existing copy on the target. If the source file is newer but not equal in version to the existing target, the file is copied.

#### SP_COPY_NOOVERWRITE

Check whether the target file exists, and, if so, notify the caller who may veto the copy. If *CopyMsgHandler* is not specified, the file is not overwritten.

#### SP_COPY_NODECOMP

Do not decompress the file. When this flag is set, the target file is not given the uncompressed form of the source name (if appropriate). For example, copying f:\x86\cmd.ex_ to \\install\temp results in a target file of \\install\temp\cmd.ex_. If the SP_COPY_NODECOMP flag was not specified, the file would be decompressed and the target would be called \\install\temp\cmd.exe. The filename part of *DestinationName*, if specified, is stripped and replaced with the filename of the source file. When SP_COPY_NODECOMP is specified, no language or version information can be checked.

#### SP_COPY_LANGUAGEAWARE

Examine each file being copied to see if its language differs from the language of any existing file already on the target. If so, and *CopyMsgHandler* is specified, the caller is notified and may cancel the copy. If *CopyMsgHandler* is not specified, the file is not copied.

#### SP_COPY_SOURCE_ABSOLUTE

*SourceFile* is a full source path. Do not look it up in the **SourceDisksNames** section of the INF file.

#### SP_COPY_SOURCEPATH_ABSOLUTE

*SourcePathRoot* is the full path part of the source file. Ignore the relative source specified in the **SourceDisksNames** section of the INF file for the source media where the file is located. This flag is ignored if SP_COPY_SOURCE_ABSOLUTE is specified.

#### SP_COPY_FORCE_IN_USE

If the target exists, behave as if it is in use and queue the file for copying on the next system reboot.

#### SP_COPY_IN_USE_NEEDS_REBOOT

If the file was in use during the copy operation, alert the user that the system needs to be rebooted.

#### SP_COPY_NOSKIP

Do not give the user the option to skip a file.

#### SP_COPY_FORCE_NOOVERWRITE

Check whether the target file exists, and, if so, the file is not overwritten. The caller is not notified.

#### SP_COPY_FORCE_NEWER

Examine each file being copied to see if its version resources (or time stamps for non-image files) indicate that it is not newer than an existing copy on the target. If the file being copied is not newer, the file is not copied. The caller is not notified.

#### SP_COPY_WARNIFSKIP

If the user tries to skip a file, warn them that skipping a file may affect the installation. (Used for system-critical files.)

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a UNC directory is specified as the target directory of a file copy operation, you must ensure it exists before the queue is committed. The setup functions do not check for the existence of and do not create UNC directories. If the target UNC directory does not exist, the file copy will fail.

> [!NOTE]
> The setupapi.h header defines SetupQueueCopy as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupQueueCopySection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopysectiona)

[SetupQueueDefaultCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedefaultcopya)

[SetupQueueDelete](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedeletea)

[SetupQueueRename](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuerenamea)