# PFNGENERATEGROUPPOLICY callback function

## Description

The
**GenerateGroupPolicy** callback function is an application-defined callback function that each policy extension must export when generating RSoP data in the planning mode. The Group Policy Data Access Service (GPDAS) calls the function after the service simulates the loading of client-side extensions so that extensions can generate policy data.

The **PFNGENERATEGROUPPOLICY** type defines a pointer to this callback function.
**GenerateGroupPolicy** is a placeholder for the application-defined function name.

## Parameters

### `dwFlags` [in]

A parameter that represents one or more of the following flags.

#### GPO_INFO_FLAG_SLOWLINK

The policy is applied across a slow link.

#### GPO_INFO_FLAG_VERBOSE

Write verbose output to the event log.

### `pbAbort` [in]

A value that specifies whether to continue processing GPOs. If this parameter is **TRUE**, GPO processing stops and the extension must deallocate its resources and return promptly. If this parameter is **FALSE**, GPO processing continues.

### `pwszSite` [in]

A pointer to the site name of the target computer. This parameter can be **NULL**.

### `pComputerTarget` [in]

A pointer to an
[RSOP_TARGET](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-rsop_target) structure that contains information about a computer. This parameter can be **NULL**, but if it is **NULL**, the *pUserTarget* parameter is required.

### `pUserTarget` [in]

A pointer to an
[RSOP_TARGET](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-rsop_target) structure that contains information about a user. This parameter can be **NULL**, but if it is **NULL**, the *pComputerTarget* parameter is required.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns one of the system error codes. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

The policy extension must register this callback function at the registry key:**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows NT**\**CurrentVersion**\**Winlogon**\**GPExtensions**\**ClientExtensionGuid**

**GenerateGroupPolicy**
**REG_SZ**

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[RSOP_TARGET](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-rsop_target)