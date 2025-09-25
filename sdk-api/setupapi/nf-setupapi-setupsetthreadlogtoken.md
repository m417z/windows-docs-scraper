# SetupSetThreadLogToken function

## Description

The **SetupSetThreadLogToken** function sets the log context, as represented by a [log token](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens), for the thread from which this function was called. A subsequent call to [SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken) made within the same thread retrieves the log token that was most recently set for the thread.

## Parameters

### `LogToken` [in]

A [log token](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens) that is either a system-defined log token or was returned by [SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken).

## Return value

None

## Remarks

**SetupSetThreadLogToken** establishes a log context for the thread from which the function was called. The log context is represented by a [log token](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens), which can be retrieved by calling [SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken).

For more information about log tokens, see [Log Tokens](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens).

For more information about using log tokens, see [Setting and Getting a Log Token for a Thread](https://learn.microsoft.com/windows-hardware/drivers/install/setting-and-getting-a-log-token-for-a-thread).

## See also

[Log Tokens](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens)

[Setting and Getting a Log Token for a Thread](https://learn.microsoft.com/windows-hardware/drivers/install/setting-and-getting-a-log-token-for-a-thread)

[SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken)