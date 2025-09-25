# PSET_RESOURCE_LOCKED_MODE_ROUTINE callback function

## Description

Reports that locked mode was configured for a resource.

## Parameters

### `ResourceHandle` [in]

A handle to the resource to configure.

### `LockedModeEnabled` [in]

**TRUE** to enable locked mode; otherwise **FALSE**.

### `LockedModeReason` [in]

A flag that specifies the reason that locked mode was configured.

## Return value

Returns **ERROR_SUCCESS** (0), if the operation succeeds; otherwise returns a system error code.

## See also

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)