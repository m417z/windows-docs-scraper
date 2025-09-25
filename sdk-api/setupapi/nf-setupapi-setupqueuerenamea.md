# SetupQueueRenameA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueueRename** function places an individual file rename operation on a setup file queue.

## Parameters

### `QueueHandle` [in]

Handle to a setup file queue, as returned by
[SetupOpenFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenfilequeue).

### `SourcePath` [in]

Pointer to a null-terminated string that specifies the source path of the file to be renamed. If *SourceFileName* is not specified, *SourcePath* is assumed to be the full path.

### `SourceFilename` [in]

Pointer to a null-terminated string that specifies the file name part of the file to be renamed. If not specified, *SourcePath* is the full path.

### `TargetPath` [in]

Pointer to a null-terminated string that specifies the target directory. When this parameter is specified, the rename operation is actually a move operation. If *TargetPath* is not specified, the file is renamed but remains in its current location.

### `TargetFilename` [in]

Pointer to a null-terminated string that specifies the new name for the source file.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Because rename operations are assumed to take place on fixed media, the user will not be prompted when the queue is committed.

> [!NOTE]
> The setupapi.h header defines SetupQueueRename as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupQueueCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopya)

[SetupQueueDelete](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedeletea)

[SetupQueueRenameSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuerenamesectiona)