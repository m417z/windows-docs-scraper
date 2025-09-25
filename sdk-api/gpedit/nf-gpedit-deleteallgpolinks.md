# DeleteAllGPOLinks function

## Description

The
**DeleteAllGPOLinks** function deletes all GPO links for the specified site, domain, or organizational unit.

## Parameters

### `lpContainer` [in]

A value that specifies the path to the site, domain, or organizational unit, in ADSI format (LDAP://cn=*user*, ou=*users*, dc=*coname*, dc=*com*). You cannot specify a server name in this parameter.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the COM error codes defined in the header file WinError.h.

## See also

[CreateGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-creategpolink)

[DeleteGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-deletegpolink)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)