# IGPEInformation::GetName

## Description

The
**GetName** method retrieves the unique name for the GPO. This value is usually a GUID.

## Parameters

### `pszName` [out]

Receives the GPO name.

### `cchMaxLength` [in]

Specifies the size, in characters, of the *pszName* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To retrieve the GPO's friendly name, which is suitable for display, you can call the
[GetDisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getdisplayname) method.

## See also

[GetDisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getdisplayname)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation)