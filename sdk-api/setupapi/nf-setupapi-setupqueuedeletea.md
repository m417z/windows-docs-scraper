# SetupQueueDeleteA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueueDelete** function places an individual file delete operation on a setup file queue.

## Parameters

### `QueueHandle` [in]

Handle to a setup file queue, as returned by
[SetupOpenFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenfilequeue).

### `PathPart1` [in]

Pointer to a **null**-terminated string that specifies the first part of the path of the file to be deleted. If *PathPart2* is **NULL**, *PathPart1* is the full path of the file to be deleted.

### `PathPart2` [in]

Pointer to a **null**-terminated string that specifies the second part of the path of the file to be deleted. This parameter may be **NULL**. This is appended to *PathPart1* to form the full path of the file to be deleted. The function checks for and collapses duplicated path separators when it combines *PathPart1* and *PathPart2*.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Because delete operations are assumed to take place on fixed media, the user will not be prompted when the queue is committed.

> [!NOTE]
> The setupapi.h header defines SetupQueueDelete as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupQueueCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopya)

[SetupQueueDeleteSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedeletesectiona)

[SetupQueueRename](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuerenamea)