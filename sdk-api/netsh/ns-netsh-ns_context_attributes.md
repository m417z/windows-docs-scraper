# NS_CONTEXT_ATTRIBUTES structure

## Description

The
**NS_CONTEXT_ATTRIBUTES** structure defines attributes of a context.

## Members

### `dwVersion`

The version of the helper.

### `dwReserved`

Reserved. Must be zero.

### `_ullAlign`

### `pwszContext`

A unicode string that identifies the new context. This string is the command available to users. The string must not contain spaces.

### `guidHelper`

A pointer to the GUID of this helper. Identical to the value passed to the
[RegisterHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registerhelper) function as the **pguidHelper** member of the
[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes) structure.

### `dwFlags`

A set of flags that limit when this context is available.

| Flag | Meaning |
| --- | --- |
| **CMD_FLAG_INTERACTIVE** | If set, context is available only when NetSh is run in interactive mode, but is not available to be passed to NetSh on the command line. |
| **CMD_FLAG_LOCAL** | If set, the context is not valid from a remote computer. |
| **CMD_FLAG_ONLINE** | If set, the context is not valid in offline mode. |
| **CMD_FLAG_PRIORITY** | If set, the ulPriority field is used. |

### `ulPriority`

A priority value used when ordering dump and commit commands. Used only when the CMD_FLAG_PRIORITY flag is set in **dwFlags**. Default value is DEFAULT_CONTEXT_PRIORITY, defined as 100 in NetSh.h. Lower values indicate higher priority.

### `ulNumTopCmds`

The number of entries in the **pTopCmds** member.

### `pTopCmds`

An array of [CMD_ENTRY](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-cmd_entry) structures that contain helper commands.

### `_CMD_ENTRY`

### `ulNumGroups`

A number of entries in the **pCmdGroups** member.

### `pCmdGroups`

An array of [CMD_GROUP_ENTRY](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-cmd_group_entry) structures that contain helper command groups.

### `_CMD_GROUP_ENTRY`

### `pfnCommitFn`

A function called to commit changes from offline mode. Can be null. For more information about the commit function, see
[NS_CONTEXT_COMMIT_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_context_commit_fn).

### `pfnDumpFn`

A function called to dump the current configuration. Can be null. For more information about the dump function, see
[NS_CONTEXT_DUMP_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_context_dump_fn).

### `pfnConnectFn`

A function called to connect to a remote computer, or to update the set of available commands. Can be null. For more information about the connect function, see [NS_CONTEXT_CONNECT_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_context_connect_fn).

### `pReserved`

Reserved. Must be null.

### `pfnOsVersionCheck`

## See also

[CMD_ENTRY](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-cmd_entry)

[CMD_GROUP_ENTRY](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-cmd_group_entry)

[NS_CONTEXT_COMMIT_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_context_commit_fn)

[NS_CONTEXT_CONNECT_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_context_connect_fn)

[NS_CONTEXT_DUMP_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_context_dump_fn)

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[NetShell Flags](https://learn.microsoft.com/previous-versions/windows/desktop/netshell/netshell-flags)