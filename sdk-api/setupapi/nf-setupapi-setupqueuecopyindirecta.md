# SetupQueueCopyIndirectA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueueCopyIndirect** function is an extended form of
[SetupQueueCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopya) passing additional parameters as a structure ([SP_FILE_COPY_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_file_copy_params_a)). Other than this, the behavior is identical.

## Parameters

### `CopyParams` [in]

Pointer to a
[SP_FILE_COPY_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_file_copy_params_a) structure that describes the file copy operation.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a UNC directory is specified as the target directory of a file copy operation, you must ensure it exists before the queue is committed. The setup functions do not check for the existence of and do not create UNC directories. If the target UNC directory does not exist, the file copy will fail.

> [!NOTE]
> The setupapi.h header defines SetupQueueCopyIndirect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).