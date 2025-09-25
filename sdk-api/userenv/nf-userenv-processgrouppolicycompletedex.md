# ProcessGroupPolicyCompletedEx function

## Description

The
**ProcessGroupPolicyCompletedEx** function notifies the system that the specified policy extension has finished applying policy. The function also reports the status of Resultant Set of Policy (RSoP) logging.

## Parameters

### `extensionId` [in]

Specifies the unique **GUID** that identifies the policy extension.

### `pAsyncHandle` [in]

Asynchronous completion handle. This handle is passed to the
[ProcessGroupPolicyEx](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicyex) callback function.

### `dwStatus` [in]

Specifies the completion status of asynchronous processing of policy.

### `RsopStatus` [in]

Specifies an **HRESULT** return code that indicates the status of RSoP logging.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns one of the system error codes. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[ProcessGroupPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicy)

[ProcessGroupPolicyCompleted](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-processgrouppolicycompleted)

[ProcessGroupPolicyEx](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicyex)