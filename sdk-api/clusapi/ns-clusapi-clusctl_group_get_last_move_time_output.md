# CLUSCTL_GROUP_GET_LAST_MOVE_TIME_OUTPUT structure

## Description

Specifies information about the last time a group was moved to another node.

## Members

### `GetTickCount64`

The number of milliseconds that have elapsed in the owning node, when the group was moved.

### `GetSystemTime`

The system date and time in the owning node, when the group was moved.

### `NodeId`

The unique ID of the node that owns the group.

## See also

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[GetTickCount64](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount64)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)