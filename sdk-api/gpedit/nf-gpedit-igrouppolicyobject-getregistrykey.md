# IGroupPolicyObject::GetRegistryKey

## Description

The
**GetRegistryKey** method retrieves a handle to the root of the registry key for the specified GPO section.

## Parameters

### `dwSection` [in]

Specifies the GPO section. This parameter can be one of the following values.

#### GPO_SECTION_ROOT

Root section

#### GPO_SECTION_MACHINE

Computer section

### `hKey` [out]

Receives a handle to the registry key. This handle is opened with all access rights. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h. If the registry information is not loaded, the method returns **E_FAIL**.

## Remarks

The registry handle is a handle to the root of the registry key. To get or set values in the
Policies key, first call the
[RegOpenKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeya) function to open the **Software**\
Policies key.

When you have finished using the registry handle, call the
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function to close the handle.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)