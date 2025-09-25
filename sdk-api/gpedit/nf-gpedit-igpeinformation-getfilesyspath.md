# IGPEInformation::GetFileSysPath

## Description

The
**GetFileSysPath** method returns the file system path for the specified section of the GPO. The path is in UNC format.

## Parameters

### `dwSection` [in]

Specifies the GPO section. This parameter can be one of the following values.

#### GPO_SECTION_ROOT

Root section

#### GPO_SECTION_USER

User section

#### GPO_SECTION_MACHINE

Computer section

### `pszPath` [out]

Receives the file system path.

### `cchMaxPath` [in]

Specifies the size, in characters, of the *pszPath* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To retrieve the Active Directory path for the specified section of a GPO, you can call the
[GetDSPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getdspath) method.

## See also

[GetDSPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getdspath)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation)