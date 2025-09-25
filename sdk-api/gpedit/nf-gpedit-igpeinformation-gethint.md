# IGPEInformation::GetHint

## Description

The
**GetHint** method retrieves the type of Active Directory object to which this GPO can be linked.

## Parameters

### `gpHint` [out]

Receives the directory service type. This parameter can be one of the following values.

#### GPHintUnknown

No link information is available.

#### GPHintMachine

The object can be linked to a computer (local or remote).

#### GPHintSite

The object can be linked to a site.

#### GPHintDomain

The object can be linked to a domain.

#### GPHintOrganizationalUnit

The object can be linked to an organizational unit.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

The Group Policy Object Editor cannot determine which Active Directory objects are linked to a particular GPO. The
**GetHint** method provides linking information based on how the user started the Group Policy Object Editor. It can be started in the following ways:

* As an extension to the Active Directory Manager. Navigate to the site, domain, or organizational unit, then select [Group Policy](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-start-page).
* As a stand-alone MMC tool with a specific link.
* As a stand-alone MMC tool without a specific link.

You may want to customize your application's user interface based on the result of calling this method. However, use this method with caution because the returned value may indicate the wrong scope.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation)