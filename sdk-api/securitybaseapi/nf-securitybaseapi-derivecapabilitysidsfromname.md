# DeriveCapabilitySidsFromName function

## Description

This function constructs two arrays of SIDs out of a capability name. One is an array group SID with NT Authority, and the other is an array of capability SIDs with AppAuthority.

## Parameters

### `CapName` [in]

Name of the capability in string form.

### `CapabilityGroupSids` [out]

The GroupSids with NTAuthority.

### `CapabilityGroupSidCount` [out]

The count of GroupSids in the array.

### `CapabilitySids` [out]

CapabilitySids with AppAuthority.

### `CapabilitySidCount` [out]

The count of CapabilitySid with AppAuthority.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller is expected to free the individual SIDs returned in each array by calling `LocalFree`, as well as memory allocated for the array itself.

The SID computed for the application capability of legacy capabilities (published prior to Win10) will be the same as the published SIDs but the SID for the service group capability SID will be hash based.