# SetupCloseFileQueue function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupCloseFileQueue** function destroys a setup file queue.

## Parameters

### `QueueHandle` [in]

Handle to an open setup file queue.

## Return value

This function does not return a value.

## Remarks

The
**SetupCloseFileQueue** function does not flush the queue; pending operations are not performed. To commit a file queue before closing it call
[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)

[SetupInstallFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfilea)

[SetupQueueCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopya)

[SetupQueueDefaultCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedefaultcopya)

[SetupQueueDelete](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedeletea)

[SetupQueueRename](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuerenamea)