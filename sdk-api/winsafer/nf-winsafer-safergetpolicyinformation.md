# SaferGetPolicyInformation function

## Description

The **SaferGetPolicyInformation** function gets information about a policy. You can query to find out more information about the policy.

## Parameters

### `dwScopeId` [in]

The scope of the query. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **SAFER_SCOPEID_MACHINE**<br><br>1 | The scope of the query is by computer. |
| **SAFER_SCOPEID_USER**<br><br>2 | The scope of the query is by user. |

### `SaferPolicyInfoClass` [in]

A [SAFER_POLICY_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/winsafer/ne-winsafer-safer_policy_info_class) enumeration value that specifies the type of policy information that should be returned. The specified value determines the size and type of the *InfoBuffer* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **SaferPolicyLevelList**<br><br>1 | Queries for the list of all levels defined in a policy.<br><br>*InfoBuffer* return type: **DWORD** array of LevelIds. |
| **SaferPolicyEnableTransparentEnforcement**<br><br>2 | Queries for the policy value to determine whether DLL checking is enabled.<br><br>*InfoBuffer* return type: **DWORD** Boolean. |
| **SaferPolicyDefaultLevel**<br><br>3 | Queries for the default policy level.<br><br>*InfoBuffer* return type: **DWORD** LevelId. |
| **SaferPolicyEvaluateUserScope**<br><br>4 | Queries to determine whether user scope rules should be consulted during policy evaluation.<br><br>*InfoBuffer* return type: **DWORD**. |
| **SaferPolicyScopeFlags**<br><br>5 | Queries to determine whether the policy is to skip members of the local administrators group.<br><br>*InfoBuffer* return type: **DWORD**. |

### `InfoBufferSize` [in]

The size, in bytes, of the *InfoBuffer* parameter.

### `InfoBuffer` [out]

A buffer to contain the results of the query. The size and type of the returned information is determined by the *SaferPolicyInfoClass* parameter. For the type of the returned information for each possible value of the *SaferPolicyInfoClass* parameter, see the *SaferPolicyInfoClass* parameter.

### `InfoBufferRetSize` [out]

The number of bytes in the *InfoBuffer* parameter that were filled with policy information.

### `lpReserved`

Reserved for future use. This parameter should be set to **NULL**.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).