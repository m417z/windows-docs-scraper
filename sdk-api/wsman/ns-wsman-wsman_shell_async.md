# WSMAN_SHELL_ASYNC structure

## Description

Defines an asynchronous structure to be passed to all shell operations. It contains an optional user context and the callback function.

## Members

### `operationContext`

Specifies the optional user context associated with the operation.

### `completionFunction`

Specifies the [WSMAN_SHELL_COMPLETION_FUNCTION](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_shell_completion_function) callback function for the operation.