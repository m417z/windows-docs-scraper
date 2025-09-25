# IDsDisplaySpecifier::GetClassCreationInfo

## Description

The **IDsDisplaySpecifier::GetClassCreationInfo** method retrieves data about the class creation wizard objects for a given object class.

## Parameters

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the attribute to obtain the **ADsType** for.

### `ppdscci` [in]

Pointer to a [DSCLASSCREATIONINFO](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsclasscreationinfo) structure pointer that receives the class creation data. This memory is allocated by this method. The caller must free this memory using [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) when it is no longer required.

## Return value

Returns a standard **HRESULT** value including the following.

## See also

[DSCLASSCREATIONINFO](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsclasscreationinfo)

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)