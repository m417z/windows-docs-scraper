# IGPMDomain::CreateGPO

## Description

Creates and retrieves a
[GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object with a default display name. Typically, the caller sets the display name immediately after calling this method.

## Parameters

### `ppNewGPO` [out]

Address of a pointer to the
[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMGPO** object.

### VB

Returns a reference to a **GPMGPO** object.

## See also

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)