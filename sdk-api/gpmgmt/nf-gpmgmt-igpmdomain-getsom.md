# IGPMDomain::GetSOM

## Description

Retrieves the [IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom) interface that represents the domain or the organizational unit (OU) at the specified path.

## Parameters

### `bstrPath` [in]

Path of the scope of management (SOM) object. The path must be a fully qualified distinguished name. Use the following syntax for the path: (ou=*MyOU*,dc=*domain_name*,dc=*com*).

**C++:** If **NULL** is specified, the method returns a pointer to the
**IGPMSOM** interface for the domain.

**Scripting:** If an empty string ("") is specified, the method returns a pointer to the
**IGPMSOM** interface for the domain.

### `ppSOM` [out]

Address of a pointer to the
[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom) interface at the specified path.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMSOM** object.

### VB

Returns a reference to a **GPMSOM** object.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom)