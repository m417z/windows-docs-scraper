# DeleteGPOLink function

## Description

The
**DeleteGPOLink** function deletes the link between the specified GPO and the specified site, domain, or organizational unit.

## Parameters

### `lpGPO` [in]

A value that specifies the path to the GPO, in ADSI format (LDAP://cn=*user*, ou=*users*, dc=*coname*, dc=*com*). You cannot specify a server name in this parameter.

### `lpContainer` [in]

Specifies the Active Directory path to the site, domain, or organizational unit.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the COM error codes defined in the header file WinError.h.

## See also

[CreateGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-creategpolink)

[DeleteAllGPOLinks](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-deleteallgpolinks)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)