# CWbemProviderGlue::SetStatusObject

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetStatusObject** method sets the parameters of a status object used to supply more information when an error occurs. This status object is derived from the [Win32_PrivilegesStatus](https://learn.microsoft.com/windows/desktop/CIMWin32Prov/win32-privilegesstatus) class.

## Parameters

### `pContext`

Pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

### `pNamespace`

Pointer to the namespace that contains the registration of the [Win32_PrivilegesStatus](https://learn.microsoft.com/windows/desktop/CIMWin32Prov/win32-privilegesstatus) class.

### `pDescription`

Pointer to the value to be put in the **Description** property of the status object instance.

### `hr`

Value to be put in the **StatusCode** property of the status object instance.

### `pPrivilegesNotHeld`

This parameter is not currently implemented and must be **NULL**.

### `pPrivilegesRequired`

Pointer to the value to be put in the **PrivilegesRequired** property of the status object instance.

## Return value

The method returns **TRUE** if successful, and **FALSE** otherwise.