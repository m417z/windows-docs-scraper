# InitializeAcl function

## Description

The **InitializeAcl** function initializes a new [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure.

## Parameters

### `pAcl` [out]

A pointer to an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure to be initialized by this function. Allocate memory for *pAcl* before calling this function.

### `nAclLength` [in]

The length, in bytes, of the buffer pointed to by the *pAcl* parameter. This value must be large enough to contain the [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) header and all of the [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) to be stored in the **ACL**. In addition, this value must be **DWORD**-aligned. For more information about calculating the size of an **ACL**, see Remarks.

### `dwAclRevision` [in]

The revision level of the [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure being created.

This value can be ACL_REVISION or ACL_REVISION_DS. Use ACL_REVISION_DS if the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) supports object-specific ACEs.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **InitializeAcl** function creates an empty [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure; the **ACL** contains no [ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace). Applying an empty **ACL** to an object denies all access to that object.

The initial size of the [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) depends on the number of [ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) you plan to add to the **ACL** before you use it. For example, if the **ACL** is to contain an ACE for a user and group, you would initialize the **ACL** based on two ACEs. For details about modifying an existing **ACL**, see [Modifying the ACLs of an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/modifying-the-acls-of-an-object-in-c--).

To calculate the initial size of an [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl), add the following together, and then align the result to the nearest **DWORD**:

* Size of the [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure.
* Size of each [ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) structure that the [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) is to contain minus the **SidStart** member (**DWORD**) of the ACE.
* Length of the SID that each [ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) is to contain.

#### Examples

The following example calls the **InitializeAcl** function. The size of the [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) is based on three allow-access [ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace). As an option, you can use [security descriptor definition language](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language) (SDDL) to create the ACL. For details, see [Creating a DACL](https://learn.microsoft.com/windows/desktop/SecBP/creating-a-dacl).

The example also omits a step for simplification. For more information, see the [Taking Object Ownership](https://learn.microsoft.com/windows/desktop/SecAuthZ/taking-object-ownership-in-c--) example. You must call the [FreeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-freesid) function at the end of the example code due to calling the [AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid) function.

```cpp
#include <windows.h>
#include <Winbase.h>
#pragma comment(lib, "duser.lib")

#define NUM_OF_ACES 3

void main()
{
    PACL pAcl = NULL;
    DWORD cbAcl = 0;
    PSID psids[NUM_OF_ACES];

    // Allocate and initialize SIDs.
    // Step omitted - See Taking Object Ownership example.

    // Add the SID for each ACE to psids.
    cbAcl = sizeof(ACL) +
        ((sizeof(ACCESS_ALLOWED_ACE)) * NUM_OF_ACES);
    for (int i = 0; i < NUM_OF_ACES; i++)
    {
        cbAcl += GetLengthSid(psids[i]) - sizeof(DWORD);
    }

    // Align cbAcl to a DWORD.
    cbAcl = (cbAcl + (sizeof(DWORD) - 1)) & 0xfffffffc;

    pAcl = (ACL*)LocalAlloc(LPTR, cbAcl);
    if (pAcl)
    {
        if (InitializeAcl(pAcl, cbAcl, ACL_REVISION))
        {

            // Add the ACEs to the ACL.
            // Add the ACL to the object's security descriptor.
        }
        else
        {

            // Handle error.
        }
    }
    {

        // Handle error.
    }

    // Free pAcl when finished.
    // Call FreeSid when finished.
}

```

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace)

[AddAccessDeniedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedace)

[AddAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addace)

[AddAuditAccessAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessace)

[DeleteAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-deleteace)

[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[IsValidAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidacl)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setaclinformation)