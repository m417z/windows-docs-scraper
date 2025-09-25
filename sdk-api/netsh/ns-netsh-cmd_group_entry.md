# CMD_GROUP_ENTRY structure

## Description

the
**CMD_GROUP_ENTRY** structure defines a group of helper commands.

## Members

### `pwszCmdGroupToken`

The token (name) for the command group

### `dwShortCmdHelpToken`

A short help message.

### `ulCmdGroupSize`

The number of elements in the command group.

### `dwFlags`

Flags. For more information, see
[NetShell Flags](https://learn.microsoft.com/previous-versions/windows/desktop/netshell/netshell-flags).

### `pCmdGroup`

An array of CMD_ENTRY structures.

### `pOsVersionCheck`

An operating system version check function. This is the function used to determine whether the command can be run on the operating system running on the local and/or remote context before invoking or displaying commands. For more information, see
[NS_OSVERSIONCHECK](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_osversioncheck).

## Remarks

Macros are available that can simplify the creation of the
**CMD_GROUP_ENTRY** structure, as follows:

``` syntax
#define CREATE_CMD_GROUP_ENTRY_EX(t,s,i)       {CMD_##t, HLP_##t, sizeof(s)/sizeof(CMD_ENTRY), i, s, NULL }
#define CREATE_CMD_GROUP_ENTRY_EX_VER(t,s,i,v) {CMD_##t, HLP_##t, sizeof(s)/sizeof(CMD_ENTRY), i, s, v }
#define CREATE_CMD_GROUP_ENTRY(t,s)            {CMD_##t, HLP_##t, sizeof(s)/sizeof(CMD_ENTRY), 0, s, NULL }

```

If these macros are used, the following constants must be defined in the helper DLL:

The following are example uses of these macros:

```cpp
#define HLP_GROUP_ADD        1100
#define HLP_GROUP_ADD_EX     1101
#define HLP_GROUP_DELETE     1102
#define HLP_GROUP_DELETE_EX  1103
#define HLP_GROUP_SET        1104
#define HLP_GROUP_SET_EX     1105
#define HLP_GROUP_SHOW       1106
#define HLP_GROUP_SHOW_EX    1107

#define CMD_GROUP_ADD        L"add"
#define CMD_GROUP_DELETE     L"delete"
#define CMD_GROUP_SET        L"set"
#define CMD_GROUP_SHOW       L"show"

static CMD_GROUP_ENTRY g_SampleGroupCmds[] =
{
    CREATE_CMD_GROUP_ENTRY(GROUP_ADD,    g_SampleAddCmdTable),
    CREATE_CMD_GROUP_ENTRY(GROUP_DELETE, g_SampleDeleteCmdTable),
    CREATE_CMD_GROUP_ENTRY(GROUP_SET,    g_SampleSetCmdTable),
    CREATE_CMD_GROUP_ENTRY(GROUP_SHOW,   g_SampleShowCmdTable),
};

```

## See also

[CMD_ENTRY](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-cmd_entry)

[NS_CONTEXT_COMMIT_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_context_commit_fn)

[NetShell Flags](https://learn.microsoft.com/previous-versions/windows/desktop/netshell/netshell-flags)