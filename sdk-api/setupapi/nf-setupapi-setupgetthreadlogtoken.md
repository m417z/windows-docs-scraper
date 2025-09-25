# SetupGetThreadLogToken function

## Description

The **SetupGetThreadLogToken** function retrieves the [log token](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens) for the thread from which this function was called.

## Return value

**SetupGetThreadLogToken** returns the log token for the thread from which the function was called. If a log token is not set for the thread, **SetupGetThreadLogToken** returns the system-defined log token LOGTOKEN_UNSPECIFIED.

## Remarks

To set a log token for a thread, call [SetupSetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetthreadlogtoken).

For more information about log tokens, see [Log Tokens](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens).

For more information about using log tokens, see [Setting and Getting a Log Token for a Thread](https://learn.microsoft.com/windows-hardware/drivers/install/setting-and-getting-a-log-token-for-a-thread).

## See also

[Log Tokens](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens)

[Setting and Getting a Log Token for a Thread](https://learn.microsoft.com/windows-hardware/drivers/install/setting-and-getting-a-log-token-for-a-thread)

[SetupSetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetthreadlogtoken)