# FwpmEngineGetSecurityInfo0 function

## Description

The **FwpmEngineGetSecurityInfo0** function retrieves a copy of the security descriptor for the filter engine.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `securityInfo` [in]

Type: **[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)**

The type of security information to retrieve.

### `sidOwner` [out, optional]

Type: **[PSID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)***

The owner security identifier (SID) in the returned security descriptor.

### `sidGroup` [out, optional]

Type: **[PSID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)***

The primary group security identifier (SID) in the returned security descriptor.

### `dacl` [out, optional]

Type: **[PACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)***

The discretionary access control list (DACL) in the returned security descriptor.

### `sacl` [out, optional]

Type: **[PACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)***

The system access control list (SACL) in the returned security descriptor.

### `securityDescriptor` [out]

Type: **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)***

The returned security descriptor.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The security descriptor was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The returned *securityDescriptor* parameter must be freed through a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0). The other four (optional) returned parameters must not be freed, as they point to addresses within the *securityDescriptor* parameter.

This function behaves like the standard Win32 [GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo) function. The caller needs the same standard access rights as described in the **GetSecurityInfo** reference topic.

**FwpmEngineGetSecurityInfo0** is a specific implementation of FwpmEngineGetSecurityInfo. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

#### Examples

The following C++ example illustrates initialization of a security descriptor object using **FwpmEngineGetSecurityInfo0**.

```cpp
#include <windows.h>
#include <fwpmu.h>
#include <stdio.h>

#pragma comment(lib, "Fwpuclnt.lib")

void main()
{
    HANDLE engineHandle = NULL;
    DWORD  result = ERROR_SUCCESS;

    PSECURITY_DESCRIPTOR securityDescriptor;
    SECURITY_INFORMATION securityInfo = OWNER_SECURITY_INFORMATION;

    // Several functions that use the SECURITY_DESCRIPTOR structure require that this
    // structure be aligned on a valid pointer boundary in memory. These boundaries
    // vary depending on the type of processor used.

    securityDescriptor = (PSECURITY_DESCRIPTOR) malloc(sizeof(SECURITY_DESCRIPTOR));

    result = FwpmEngineOpen0( NULL, RPC_C_AUTHN_WINNT, NULL, NULL, &engineHandle );
    if (result != ERROR_SUCCESS)
    {
        printf("FwpmEngineOpen0 failed.\n");
        return;
    }

    result = FwpmEngineGetSecurityInfo0(
                 engineHandle,
                 securityInfo,
                 NULL,
                 NULL,
                 NULL,
                 NULL,
                 &securityDescriptor);

    if (result != ERROR_SUCCESS)
    {
        printf("FwpmEngineGetSecurityInfo0 failed.\n");
        return;
    }

    return;
}

```

## See also

[FwpmEngineSetSecurityInfo0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmenginesetsecurityinfo0)