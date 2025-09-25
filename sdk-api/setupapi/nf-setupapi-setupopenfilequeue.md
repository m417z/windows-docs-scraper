# SetupOpenFileQueue function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupOpenFileQueue** function creates a setup file queue.

## Return value

If the function succeeds, it returns a handle to a setup file queue. If there is not enough memory to create the queue, the function returns INVALID_HANDLE_VALUE. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After the file queue has been committed and is no longer needed,
[SetupCloseFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupclosefilequeue) should be called to release the resources allocated during
**SetupOpenFileQueue**.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCloseFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupclosefilequeue)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)

[SetupInstallFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfilea)

[SetupQueueCopy](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopya)

[SetupQueueDelete](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuedeletea)

[SetupQueueRename](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuerenamea)