# IGPEInformation::GetDisplayName

## Description

The
**GetDisplayName** method retrieves the display name for the GPO.

## Parameters

### `pszName` [out]

Receives the display name for the GPO.

### `cchMaxLength` [in]

Specifies the size, in characters, of the *pszName* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To retrieve the unique name for the GPO (typically a GUID), you can call the
[GetName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getname) method.

## See also

[GetName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getname)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation)