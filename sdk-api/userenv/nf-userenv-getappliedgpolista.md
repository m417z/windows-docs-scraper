# GetAppliedGPOListA function

## Description

The
**GetAppliedGPOList** function retrieves the list of GPOs applied for the specified user or computer.

## Parameters

### `dwFlags` [in]

A value that specifies the policy type. This parameter can be the following value.

#### GPO_LIST_FLAG_MACHINE

Retrieves information about the computer policy.

If this value is not specified, the function retrieves only user policy information.

### `pMachineName` [in]

A pointer to the name of the remote computer. The format of the name is "\\*computer_name*". If this parameter is **NULL**, the local computer name is used.

### `pSidUser` [in]

A value that specifies the SID of the user. If *pMachineName* is not **NULL** and *dwFlags* specifies user policy, then *pSidUser* cannot be **NULL**.

If *pMachineName* is **NULL** and *pSidUser* is **NULL**, the user is the currently logged-on user. If *pMachineName* is **NULL** and *pSidUser* is not **NULL**, the user is represented by *pSidUser* on the local computer. For more information, see
[Security Identifiers](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers).

### `pGuidExtension` [in]

A value that specifies the **GUID** of the extension.

### `ppGPOList` [out]

A pointer that receives the list of GPO structures. For more information, see
[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns a system error code. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

To free the GPO list when you have finished processing it, call the
[FreeGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-freegpolista) function.

> [!NOTE]
> The userenv.h header defines GetAppliedGPOList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FreeGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-freegpolista)

[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta)

[GetGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getgpolista)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)