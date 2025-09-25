# SetupTermDefaultQueueCallback function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupTermDefaultQueueCallback** function is called after a queue has finished committing. It frees resources allocated by previous calls to
[SetupInitDefaultQueueCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallback) or
[SetupInitDefaultQueueCallbackEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallbackex).

## Parameters

### `Context` [in]

Pointer to the context used by the default callback routine.

## Return value

Does not return a value.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Regardless of whether you initialized the context used by the default queue callback routine with
[SetupInitDefaultQueueCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallback) or
[SetupInitDefaultQueueCallbackEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallbackex), after the queued operations have finished processing, call
**SetupTermDefaultQueueCallback** to release the resources allocated in initializing the context structure. For more information see
[Initializing and Terminating the Callback Context](https://learn.microsoft.com/windows/desktop/SetupApi/initializing-and-terminating-the-callback-context).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupInitDefaultQueueCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallback)

[SetupInitDefaultQueueCallbackEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallbackex)