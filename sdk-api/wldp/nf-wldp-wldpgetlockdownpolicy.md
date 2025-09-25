## Description

Calls the library to get the security state relative to the host, and script or msi to be used. The function has no associated import library. You must use the LoadLibrary and GetProcAddress functions to dynamically link to wldp.dll.

## Parameters

### `hostInformation`

A [**WLDP\_HOST\_INFORMATION**](https://learn.microsoft.com/windows/win32/api/wldp/ns-wldp-wldp_host_information) structure identifying the host and source file to be evaluated.

### `lockdownState`

Provides the resulting policy secure value. If !WLDP_LOCKDOWN_IS_OFF, then UMCI is enabled. You can also check WLDP_LOCKDOWN_IS_AUDIT and WLDP_LOCKDOWN_IS_ENFORCE to determine if a policy is in audit or enforce mode.

### `lockdownFlags`

The following flag values are defined WLDP\_FLAGS\_SKIPSIGNATUREVALIDATION 0x00000100 – when set, skip the SaferIdentifyLevel validation, which will ignore whether a script is signed.

## Return value

This method returns S\_OK if successful or a failure code otherwise.

## Remarks

> [!NOTE]
> [WldpCanExecuteBuffer](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutebuffer), [WldpCanExecuteFile](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutefile), and [WldpCanExecuteStream](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutestream) are newer APIs that enable the same scenarios as **WldpGetLockdownPolicy** but with an improved implementation.

When called with WLDP\_HOST\_INFORMATION.szSource = NULL, the generic policy for the host is returned.

When called with WLDP\_HOST\_INFORMATION.dwHostId = WLDP\_HOST\_ID\_GLOBAL, WLDP\_HOST\_INFORMATION.szSource must be NULL, and the function will return the global system policy.

The dwFlag WLDP\_FLAGS\_SKIPSIGNATUREVALIDATION can be used to skip the SaferIdentifyLevel() validation, which will ignore whether a script is signed.

## See also