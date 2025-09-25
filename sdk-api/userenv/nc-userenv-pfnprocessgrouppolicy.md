# PFNPROCESSGROUPPOLICY callback function

## Description

The
**ProcessGroupPolicy** function is an application-defined callback function used when applying policy. The **PFNPROCESSGROUPPOLICY** type defines a pointer to this callback function.
**ProcessGroupPolicy** is a placeholder for the application-defined function name.

This callback function is not useful for Resultant Set of Policy (RSoP) processing; use the
[ProcessGroupPolicyEx](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicyex) callback function instead.

## Parameters

### `dwFlags` [in]

This parameter can be one or more of the following flags.

#### GPO_INFO_FLAG_MACHINE

Apply computer policy rather than user policy.

#### GPO_INFO_FLAG_BACKGROUND

Perform a background refresh of the policy.

#### GPO_INFO_FLAG_ASYNC_FOREGROUND

Perform an asynchronous foreground refresh of policy. For more information about foreground policy application, see
[Initial Processing of Group Policy](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/initial-processing-of-group-policy).

#### GPO_INFO_FLAG_SLOWLINK

The policy is being applied across a slow link.

#### GPO_INFO_FLAG_VERBOSE

Write verbose output to the event log.

#### GPO_INFO_FLAG_NOCHANGES

No changes to the GPO were detected.

#### GPO_INFO_FLAG_LINKTRANSITION

A change in the link speed was detected between policy applications.

#### GPO_INFO_FLAG_LOGRSOP_TRANSITION

A change in RSoP logging was detected between the application of the previous policy and the application of the current policy.

#### GPO_INFO_FLAG_FORCED_REFRESH

A forced policy refresh is being applied.

#### GPO_INFO_FLAG_SAFEMODE_BOOT

Safe mode flag.

### `hToken` [in]

Token for the user or computer, returned from the
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera),
[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken),
[DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken),
[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or
[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function. This token must have **TOKEN_IMPERSONATE** and **TOKEN_QUERY** access. For more information, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects) and
[Client Impersonation](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-impersonation).

### `hKeyRoot` [in]

Handle to the **HKEY_LOCAL_MACHINE** or **HKEY_CURRENT_USER** registry key.

### `pDeletedGPOList` [in]

Pointer that receives the list of deleted GPO structures. For more information, see
[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta).

### `pChangedGPOList` [in]

Pointer that receives the list of changed GPO structures. For more information, see
[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta).

### `pHandle` [in]

Asynchronous completion handle. If the callback function does not support asynchronous processing, this handle is zero.

### `pbAbort` [in]

Specifies whether to continue processing GPOs. If this parameter is **TRUE**, GPO processing will cease. If this parameter is **FALSE**, GPO processing will continue.

### `pStatusCallback` [in]

Pointer to a
[StatusMessageCallback](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnstatusmessagecallback) callback function that displays status messages. This parameter can be **NULL** in certain cases. For example, if the system is applying policy in the background, the status user interface is not present and the application cannot send status messages to be displayed. For more information, see the following Remarks section.

## Return value

If policy was applied successfully, return **ERROR_SUCCESS**. If there are no changes to the GPO list, and the extension is to be called again, return **ERROR_OVERRIDE_NOCHANGES**. Returning **ERROR_OVERRIDE_NOCHANGES** ensures that the extension is called again, even if the **NoGPOListChanges** registry value is set. (For more information about this registry value, see Remarks.) Otherwise, return a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

For more information, see
[Implementing a Group Policy Client-side Extension](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/implementing-a-group-policy-client-side-extension).

The system calls this function in the context of the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account), which has extensive privileges on the local computer. To use network resources, you must impersonate the user or computer by using the token provided in the *hToken* parameter.

To register this callback function, create a subkey under the following registry key:

**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows NT**\**CurrentVersion**\**Winlogon**\**GPExtensions**\**ClientExtensionGuid**

The subkey should be a **GUID**, so that it is unique. It should contain the following values.

You should update the status message only if you are applying policy synchronously. This allows you to provide feedback and diagnostics during a lengthy policy application. To use the status message callback function, you must verify that *pStatusCallback* is not **NULL**. Then load your message string resource. When you call the status function, you must indicate whether the string is verbose. If the string is verbose, the callback function will verify that the computer is in verbose mode and display the message. For more information, see
[StatusMessageCallback](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnstatusmessagecallback).

**Warning** Do not call the *pStatusCallback* function from a background thread because you may overwrite another thread's status message.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[ProcessGroupPolicyCompleted](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-processgrouppolicycompleted)

[RefreshPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-refreshpolicy)

[StatusMessageCallback](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnstatusmessagecallback)