# FN_HANDLE_CMD callback function

## Description

The
**FN_HANDLE_CMD** command is the command function for helpers. Helpers expose commands through the *pTopCmds* and *pCmdGroups* parameters in the
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The following is an example of a command function. Be aware that **SampleCommand** is a placeholder for the application-defined function name.

## Parameters

### `pwszMachine` [in]

The name of the computer on which to perform the command, or null if the command applies to the local computer. The default value is null.

If the context uses a connect function, this argument can be ignored.

### `ppwcArguments` [in]

A set of command tokens.

### `dwCurrentIndex` [in]

The current index into *ppwcArguments* of the last token processed before the function was called.

### `dwArgCount` [in]

The number of arguments in the *ppwcArguments* parameter.

### `dwFlags` [in]

The command flags that pertain to the current state.

### `pvData` [in]

A data pointer. Value is null unless changed by a parent context **SubEntry** function.

### `pbDone` [out]

A set *pbDone* to **TRUE** before returning to instruct NetShell to terminate after the command function completes. The *pbDone* parameter is set to **FALSE** by default.

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## Remarks

The computer name specified in *pwszMachine* is passed to each function, so a connect function is not required, as would be the case if a helper has only one command. Helpers with multiple commands can create remotability code in the connect function, rather than duplicating it in each command function.

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)