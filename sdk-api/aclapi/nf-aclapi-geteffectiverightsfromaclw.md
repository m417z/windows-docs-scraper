# GetEffectiveRightsFromAclW function

## Description

[**GetEffectiveRightsFromAcl** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the method demonstrated in the example below.]

The **GetEffectiveRightsFromAcl** function retrieves the effective access rights that an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure grants to a specified trustee. The trustee's effective access rights are the access rights that the **ACL** grants to the trustee or to any groups of which the trustee is a member.

## Parameters

### `pacl` [in]

A pointer to an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure from which to get the trustee's effective access rights.

### `pTrustee` [in]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that identifies the trustee. A trustee can be a user, group, or program (such as a Windows service). You can use a name or a security identifier ([SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)) to identify a trustee.

### `pAccessRights` [out]

A pointer to an
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) variable that receives the effective access rights of the trustee.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

The **GetEffectiveRightsFromAcl** function checks all access-allowed and access-denied [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) to determine the effective rights for the trustee. For all ACEs that allow or deny rights to a group, **GetEffectiveRightsFromAcl** enumerates the members of the group to determine whether the trustee is a member. The function returns an error if it cannot enumerate the members of a group.

A trustee's group rights are enumerated by **GetEffectiveRightsFromAcl** on the local computer, even if the trustee is accessing objects on a remote computer. This function does not evaluate group rights on remote computers.

The **GetEffectiveRightsFromAcl** function does not consider the following:

* Implicitly granted access rights, such as READ_CONTROL and WRITE_DAC, for the owner of an object when determining effective rights.
* Privileges held by the trustee when determining effective access rights.
* Group rights associated with the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), such as interactive, network, authenticated users, and so forth, in determining effective access rights.
* [Resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) policy. For example, for file objects, Delete and Read attributes can be provided by the parent even if they have been denied on the object.

The **GetEffectiveRightsFromAcl** function fails and returns **ERROR_INVALID_ACL** if the specified ACL contains an inherited access-denied ACE.

#### Examples

The following example shows using [Authz API](https://learn.microsoft.com/windows/desktop/SecAuthZ/using-authz-api) to get effective access rights from an ACL.

```cpp

//  Copyright (C) Microsoft. All rights reserved.

#include <windows.h>
#include <stdio.h>
#include <aclapi.h>
#include <tchar.h>
#include <strsafe.h> // for proper buffer handling
#include <authz.h>

#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "authz.lib")

LPTSTR lpServerName = NULL;

PSID ConvertNameToBinarySid(LPTSTR pAccountName)
{
   LPTSTR pDomainName = NULL;
   DWORD dwDomainNameSize = 0;
   PSID pSid = NULL;
   DWORD dwSidSize = 0;
   SID_NAME_USE sidType;
   BOOL fSuccess = FALSE;
   HRESULT hr = S_OK;

   __try
   {
      LookupAccountName(
            lpServerName,      // look up on local system
            pAccountName,
            pSid,              // buffer to receive name
            &dwSidSize,
            pDomainName,
            &dwDomainNameSize,
            &sidType);

      //  If the Name cannot be resolved, LookupAccountName will fail with
      //  ERROR_NONE_MAPPED.
      if (GetLastError() == ERROR_NONE_MAPPED)
      {
         wprintf_s(_T("LookupAccountName failed with %d\n"), GetLastError());
         __leave;
      }
      else if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
      {
         pSid = (LPTSTR)LocalAlloc(LPTR, dwSidSize * sizeof(TCHAR));
         if (pSid == NULL)
         {
            wprintf_s(_T("LocalAlloc failed with %d\n"), GetLastError());
            __leave;
         }

         pDomainName = (LPTSTR)LocalAlloc(LPTR, dwDomainNameSize * sizeof(TCHAR));
         if (pDomainName == NULL)
         {
            wprintf_s(_T("LocalAlloc failed with %d\n"), GetLastError());
            __leave;
         }

         if (!LookupAccountName(
               lpServerName,      // look up on local system
               pAccountName,
               pSid,              // buffer to receive name
               &dwSidSize,
               pDomainName,
               &dwDomainNameSize,
               &sidType))
         {
            wprintf_s(_T("LookupAccountName failed with %d\n"), GetLastError());
            __leave;
         }
      }

      //  Any other error code
      else
      {
         wprintf_s(_T("LookupAccountName failed with %d\n"), GetLastError());
         __leave;
      }

      fSuccess = TRUE;
   }
   __finally
   {
      if(pDomainName != NULL)
      {
          LocalFree(pDomainName);
          pDomainName = NULL;
      }

      //  Free pSid only if failed;
      //  otherwise, the caller has to free it after use.
      if (fSuccess == FALSE)
      {
         if(pSid != NULL)
      {
          LocalFree(pSid);
          pSid = NULL;
      }
      }
   }

   return pSid;
}

void DisplayError(char* pszAPI, DWORD dwError)
{
   LPVOID lpvMessageBuffer;

   if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM,
              GetModuleHandle(L"Kernel32.dll"), dwError,
              MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  // the user default language
              (LPTSTR)&lpvMessageBuffer, 0, NULL))
   {
      wprintf_s(L"FormatMessage failed with %d\n", GetLastError());
      ExitProcess(GetLastError());
   }

   //  ...now display this string.
   wprintf_s(L"ERROR: API        = %s.\n", (char *)pszAPI);
   wprintf_s(L"       error code = %08X.\n", dwError);
   wprintf_s(L"       message    = %s.\n", (char *)lpvMessageBuffer);

   //  Free the buffer allocated by the system.
   LocalFree(lpvMessageBuffer);

   ExitProcess(GetLastError());
}

void DisplayAccessMask(ACCESS_MASK Mask)
{
      // This evaluation of the ACCESS_MASK is an example.
      // Applications should evaluate the ACCESS_MASK as necessary.

   wprintf_s(L"Effective Allowed Access Mask : %8X\n", Mask);
   if (((Mask & GENERIC_ALL) == GENERIC_ALL)
      || ((Mask & FILE_ALL_ACCESS) == FILE_ALL_ACCESS))
   {
         wprintf_s(L"Full Control\n");
         return;
   }
   if (((Mask & GENERIC_READ) == GENERIC_READ)
      || ((Mask & FILE_GENERIC_READ) == FILE_GENERIC_READ))
         wprintf_s(L"Read\n");
   if (((Mask & GENERIC_WRITE) == GENERIC_WRITE)
      || ((Mask & FILE_GENERIC_WRITE) == FILE_GENERIC_WRITE))
         wprintf_s(L"Write\n");
   if (((Mask & GENERIC_EXECUTE) == GENERIC_EXECUTE)
      || ((Mask & FILE_GENERIC_EXECUTE) == FILE_GENERIC_EXECUTE))
         wprintf_s(L"Execute\n");

}

void GetAccess(AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClient, PSECURITY_DESCRIPTOR psd)
{
   AUTHZ_ACCESS_REQUEST AccessRequest = {0};
   AUTHZ_ACCESS_REPLY AccessReply = {0};
   BYTE     Buffer[1024];
   BOOL bRes = FALSE;  // assume error

   //  Do AccessCheck.
   AccessRequest.DesiredAccess = MAXIMUM_ALLOWED;
   AccessRequest.PrincipalSelfSid = NULL;
   AccessRequest.ObjectTypeList = NULL;
   AccessRequest.ObjectTypeListLength = 0;
   AccessRequest.OptionalArguments = NULL;

   RtlZeroMemory(Buffer, sizeof(Buffer));
   AccessReply.ResultListLength = 1;
   AccessReply.GrantedAccessMask = (PACCESS_MASK) (Buffer);
   AccessReply.Error = (PDWORD) (Buffer + sizeof(ACCESS_MASK));

   if (!AuthzAccessCheck( 0,
                          hAuthzClient,
                          &AccessRequest,
                          NULL,
                          psd,
                          NULL,
                          0,
                          &AccessReply,
                          NULL) ) {
      wprintf_s(_T("AuthzAccessCheck failed with %d\n"), GetLastError());
   }
   else
      DisplayAccessMask(*(PACCESS_MASK)(AccessReply.GrantedAccessMask));

   return;
}

BOOL GetEffectiveRightsForUser(AUTHZ_RESOURCE_MANAGER_HANDLE hManager,
                               PSECURITY_DESCRIPTOR psd,
                                      LPTSTR lpszUserName)
{
   PSID pSid = NULL;
   BOOL bResult = FALSE;
   LUID unusedId = { 0 };
   AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext = NULL;

   pSid = ConvertNameToBinarySid(lpszUserName);
   if (pSid != NULL)
   {
      bResult = AuthzInitializeContextFromSid(0,
         pSid,
         hManager,
         NULL,
         unusedId,
         NULL,
         &hAuthzClientContext);
      if (bResult)
      {
         GetAccess(hAuthzClientContext, psd);
         AuthzFreeContext(hAuthzClientContext);
      }
      else
         wprintf_s(_T("AuthzInitializeContextFromSid failed with %d\n"), GetLastError());
   }
    if(pSid != NULL)
      {
          LocalFree(pSid);
          pSid = NULL;
      }

   return bResult;
}

void UseAuthzSolution(PSECURITY_DESCRIPTOR psd, LPTSTR lpszUserName)
{
   AUTHZ_RESOURCE_MANAGER_HANDLE hManager;
   BOOL bResult = FALSE;

   bResult = AuthzInitializeResourceManager(AUTHZ_RM_FLAG_NO_AUDIT,
      NULL, NULL, NULL, NULL, &hManager);
   if (bResult)
   {
      bResult = GetEffectiveRightsForUser(hManager, psd, lpszUserName);
      AuthzFreeResourceManager(hManager);
   }
   else
      wprintf_s(_T("AuthzInitializeResourceManager failed with %d\n"), GetLastError());
}

void wmain(int argc, wchar_t *argv[])
{
   DWORD                dw;
   PACL                 pacl;
   PSECURITY_DESCRIPTOR psd;
   PSID                 psid = NULL;

   if (argc != 3)
   {
      wprintf_s(L"Usage: FileOrFolderName UserOrGroupName\n");
      wprintf_s(L"Usage: FileOrFolderName UserOrGroupName\n");
      return;
   }

    dw = GetNamedSecurityInfo(argv[1], SE_FILE_OBJECT, DACL_SECURITY_INFORMATION |
      OWNER_SECURITY_INFORMATION |
      GROUP_SECURITY_INFORMATION, NULL, NULL, &pacl, NULL, &psd);
   if (dw != ERROR_SUCCESS)
   {  printf("couldn't do getnamedsecinfo \n");
      DisplayError("GetNamedSecurityInfo", dw);
   }

   UseAuthzSolution(psd, argv[2]);

   if(psid != NULL)
      {
          LocalFree(psid);
          psid = NULL;
      };

   LocalFree(psd);
}

```

> [!NOTE]
> The aclapi.h header defines GetEffectiveRightsFromAcl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetAuditedPermissionsFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getauditedpermissionsfromacla)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)