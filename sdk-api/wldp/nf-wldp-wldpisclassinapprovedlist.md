## Description

Calls the library to validate if a particular **CLSID** is safe to be called. The function has no associated import library. You must use the LoadLibrary and GetProcAddress functions to dynamically link to wldp.dll.

## Parameters

### `classID`

The COM class ID to check for approval.

### `hostInformation`

A [**WLDP\_HOST\_INFORMATION**](https://learn.microsoft.com/windows/win32/api/wldp/ns-wldp-wldp_host_information) structure identifying the host to be evaluated.

### `isApproved`

On successful completion, contains **TRUE** if the class ID is approved; otherwise, **FALSE**.

### `optionalFlags`

This parameter is reserved and must be set to zero.

## Return value

This method returns **S\_OK** if successful or a failure code otherwise.

## Remarks

## See also