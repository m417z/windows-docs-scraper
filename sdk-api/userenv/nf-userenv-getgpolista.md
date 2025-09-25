# GetGPOListA function

## Description

The
**GetGPOList** function retrieves the list of GPOs for the specified user or computer. This function can be called in two ways: first, you can use the token for the user or computer, or, second, you can use the name of the user or computer and the name of the domain controller.

## Parameters

### `hToken` [in]

A token for the user or computer, returned from the
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera),
[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken),
[DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken),
[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or
[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function. This token must have **TOKEN_IMPERSONATE** and **TOKEN_QUERY** access. For more information, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects) and the following Remarks section.

If this parameter is **NULL**, you must supply values for the *lpName* and *lpHostName* parameters.

### `lpName` [in]

A pointer to the user or computer name, in the fully qualified distinguished name format (for example, "CN=*user*, OU=*users*, DC=*contoso*, DC=*com*").

If the *hToken* parameter is not **NULL**, this parameter must be **NULL**.

### `lpHostName` [in]

A DNS domain name (preferred) or domain controller name. Domain controller name can be retrieved using the
[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function, specifying **DS_DIRECTORY_SERVICE_REQUIRED** in the *flags* parameter.

If the *hToken* parameter is not **NULL**, this parameter must be **NULL**.

### `lpComputerName` [in]

A pointer to the name of the computer used to determine the site location. The format of the name is "\\*computer_name*". If this parameter is **NULL**, the local computer name is used.

### `dwFlags` [in]

A value that specifies additional flags that are used to control information retrieval. If you specify **GPO_LIST_FLAG_MACHINE**, the function retrieves policy information for the computer. If you do not specify **GPO_LIST_FLAG_MACHINE**, the function retrieves policy information for the user.

If you specify **GPO_LIST_FLAG_SITEONLY** the function returns only site information for the computer or user.

### `pGPOList` [out]

A pointer that receives the list of GPO structures. For more information, see
[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetGPOList** function is intended for use by services acting on behalf of a user or computer. The service calls this function to obtain a list of GPOs, then checks each GPO for service-specific policy.

Calling this function with a token provides the most accurate list. The system can perform access checking for the user or computer. Calling this function with the user or computer name and the domain controller name is faster than calling it with a token. However, if the token is not specified, the system uses the security access of the caller, which means that the list may not be completely correct for the intended user or computer.

To obtain the most accurate list of GPOs for a computer when calling **GetGPOList**, the caller must have read access to each OU and site in the computer domain, and also read and apply Group Policy access to all GPOs that are linked to the sites, domain or OUs of that domain. An example of a caller would be a service running on the computer whose name is specified in the *lpName* parameter. An alternate method of obtaining a list of GPOs would be to call the [RsopCreateSession](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsopplanningmodeprovider-rsopcreatesession) method of the **RsopPlanningModeProvider** WMI class. The method can generate resultant policy data for a computer or user account in a hypothetical scenario.

Call the
[FreeGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-freegpolista) function to free the GPO list when you have finished processing it.

Generally, you should call
**GetGPOList** with a token when retrieving a list of GPOs for a user as shown in the following code example.

```cpp
LPGROUP_POLICY_OBJECT  pGPOList;
      if (GetGPOList (hToken, NULL, NULL, NULL, 0, &pGPOList))
      {
//        Perform processing here.
//
//        Free the GPO list when you finish processing.
          FreeGPOList (pGPOList);
      }
```

Typically, to retrieve a list of GPOs for a computer, you can call
**GetGPOList** with the computer name and domain controller name as demonstrated in the following code snippet.

```cpp
LPGROUP_POLICY_OBJECT  pGPOList;
      if (GetGPOList (NULL, lpMachineName, lpHostName, lpMachineName, GPO_LIST_FLAG_MACHINE, &pGPOList))
      {
//        Perform processing here.
//
//        Free the GPO list when you finish processing.
          FreeGPOList (pGPOList);
      }
```

To retrieve the list of GPOs applied for a specific user or computer and extension, call the
[GetAppliedGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getappliedgpolista) function.

> [!NOTE]
> The userenv.h header defines GetGPOList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

[FreeGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-freegpolista)

[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)