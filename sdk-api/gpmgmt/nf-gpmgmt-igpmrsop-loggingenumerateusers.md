# IGPMRSOP::LoggingEnumerateUsers

## Description

Enumerates all users who have logging mode data on a specific computer.

## Parameters

### `varVal` [out]

Pointer to a SAFEARRAY containing VARIANT members. Each VARIANT contains a Dispatch pointer to the
[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns an array of **GPMTrustee** object references. Note that the array is a normal array, not a GPMC collection.

### VB

Returns an array of **GPMTrustee** object references. Note that the array is a normal array, not a GPMC collection.

## See also

[IGPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop)

[IGPMTrustee](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmtrustee)