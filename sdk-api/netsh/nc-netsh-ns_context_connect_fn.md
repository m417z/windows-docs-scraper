# NS_CONTEXT_CONNECT_FN callback function

## Description

The
**NS_CONTEXT_CONNECT_FN** command is the connect function for helpers. Helpers expose a connect function that enables NetShell to connect to the helper. NetShell calls a helper connect function before calling other helper functions.

The connect function is registered with NetShell using the
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The following is an example of a connect function. Be aware that **SampleConnect** is a placeholder for the application-defined function name.

## Parameters

### `pwszMachine` [in]

The computer on which to perform the command, or null if the command applies to the local computer. The default value is null.

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## Remarks

A helper connect function is called by NetShell before NetShell calls the context dump function, if one exists, and before any command function. Two operations should be carried out during a connect function call.

If the context is remotable, specified by absence of the CMD_FLAG_LOCAL flag, the connect function should accept the computer name on which the function should operate next, and attempt to validate its ability to communicate with that computer.

If the context commands are dynamic, the context should call
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) again with its latest set of commands.

Each helper is responsible for maintaining its own connection to remote computers. If access is not possible, a helper should display an appropriate error message, and must fail on the connect function.

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[NetShell Flags](https://learn.microsoft.com/previous-versions/windows/desktop/netshell/netshell-flags)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)