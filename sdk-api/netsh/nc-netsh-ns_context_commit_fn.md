# NS_CONTEXT_COMMIT_FN callback function

## Description

The
**NS_CONTEXT_COMMIT_FN** command is the commit function for helpers. The commit function commits commands used for committing offline commands, and is registered in the
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The following is an example of a commit function. Be aware that **SampleCommit** is a placeholder for the application-defined function name.

## Parameters

### `dwAction` [in]

A value that specifies the commit action. Must be one of the following.

| Value | Meaning |
| --- | --- |
| **NETSH_COMMIT** | Changes to commit mode. |
| **NETSH_UNCOMMIT** | Changes to uncommit mode. |
| **NETSH_SAVE** | Saves all uncommitted changes. |
| **NETSH_FLUSH** | Flushes all uncommitted changes. |

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)