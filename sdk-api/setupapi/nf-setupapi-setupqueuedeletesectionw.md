# SetupQueueDeleteSectionW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueueDeleteSection** function queues all the files in a section of an INF file for deletion. The section must be in the correct **Delete Files** format and the INF file must contain a **DestinationDirs** section.

## Parameters

### `QueueHandle` [in]

Handle to a setup file queue, as returned by
[SetupOpenFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenfilequeue).

### `InfHandle` [in]

Handle to an open INF file that contains the **DestinationDirs** section. If *ListInfHandle* is not specified, *InfHandle* contains the section name.

### `ListInfHandle` [in]

Optional handle to an open INF file that contains the section to queue for deletion. If *ListInfHandle* is not specified, *InfHandle* is assumed to contain the section name.

### `Section` [in]

Pointer to a null-terminated string that specifies the name of the section to be queued for deletion.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function requires a Windows INF file. Some older INF file formats may not be supported.

> [!NOTE]
> The setupapi.h header defines SetupQueueDeleteSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupQueueCopySection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopysectiona)

[SetupQueueDelete](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedeletea)

[SetupQueueRenameSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuerenamesectiona)