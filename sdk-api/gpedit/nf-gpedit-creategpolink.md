# CreateGPOLink function

## Description

The **CreateGPOLink** function creates a link between
the specified GPO and the specified site, domain, or organizational unit.

## Parameters

### `lpGPO` [in]

A value that specifies the path to the GPO, in ADSI format
("LDAP://cn=*user*, ou=*users*, dc=*coname*, dc=*com*").
You cannot specify a server name in this parameter.

### `lpContainer` [in]

A value that specifies the Active Directory path to the site, domain, or organizational unit.

### `fHighPriority` [in]

A value that specifies the link priority. If this parameter is **TRUE**, the system
creates the link as the highest priority. If this parameter is **FALSE**, the system
creates the link as the lowest priority.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns
one of the COM error codes defined in the header file WinError.h. Be aware that you should test explicitly for
the return value **S_OK**. Do not use the **SUCCEEDED** or
**FAILED** macro on the returned **HRESULT** to determine success or failure of the
function.

## See also

[DeleteAllGPOLinks](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-deleteallgpolinks)

[DeleteGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-deletegpolink)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)