# ITargetInfo::ExpandTarget

## Description

Expands a location string to indicate the offline installation location.

## Parameters

### `Offline` [in]

**True** if the installation location is offline.

### `Location` [in]

The location string.

### `ExpandedLocation` [out]

The expanded location string.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. This method may return **E_OUTOFMEMORY** if there are insufficient resources to return information to the user.

## See also

[ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo)