# SearchScope enumeration

## Description

Defines the variety of updates that should be returned by the search: per-machine updates, per-user updates, or both.

## Constants

### `searchScopeDefault:0`

Search by using the default scope (the scope that Automatic Updates would use when searching for updates). This is currently equivalent to search ScopeMachineOnly.

### `searchScopeMachineOnly:1`

Search only for per-machine updates; exclude all per-user updates.

### `searchScopeCurrentUserOnly:2`

Search only for per-user updates applicable to the calling user – the user who owns the process which is making the Windows Update Agent (WUA) API call.

### `searchScopeMachineAndCurrentUser:3`

[Not currently supported.] Search for per-machine updates and for per-user updates applicable to the current user.

### `searchScopeMachineAndAllUsers:4`

[Not currently supported.] Search for per-machine updates and for per-user updates applicable to any known user accounts on the computer.

### `searchScopeAllUsers:5`

[Not currently supported.] Search only for per-user updates applicable to any known user accounts on the computer.

## Remarks

In versions of the Windows Update Agent that do not support per-user updates (versions that do not support the [IUpdateSearcher3](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher3) interface), searches will always return only per-machine updates.