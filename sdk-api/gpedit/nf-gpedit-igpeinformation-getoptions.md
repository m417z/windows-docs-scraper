# IGPEInformation::GetOptions

## Description

The
**GetOptions** method retrieves the options the user has selected for the Group Policy Object Editor.

## Parameters

### `dwOptions` [out]

Receives a bitmask value representing the options the user has selected. Currently, this parameter returns only zero.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation)