# IGPMSitesContainer::GetSite

## Description

Returns the scope of management (SOM) object that corresponds to the site.

## Parameters

### `bstrSiteName` [in]

Required. The site of interest; for example, Default-first-site-name. Use null-terminated string.

### `ppSOM` [out]

Address of a pointer to the
[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMSOM** object.

### VB

Returns a reference to a **GPMSOM** object.

## See also

[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom)

[IGPMSitesContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsitescontainer)