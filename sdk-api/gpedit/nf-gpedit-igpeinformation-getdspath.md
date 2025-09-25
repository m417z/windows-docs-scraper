# IGPEInformation::GetDSPath

## Description

The
**GetDSPath** method retrieves the Active Directory path for the specified section of the GPO.

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

Receives the Active Directory path to the root of the requested section. For more information, see the following Remarks section.

### `cchMaxPath` [in]

Specifies the size, in characters, of the *pszPath* parameter.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

If you call the
**GetDSPath** method and specify a computer GPO, the method succeeds, but on return, the *pszPath* parameter contains an empty string. This is because computer GPOs do not have Active Directory storage; they have only file system storage.

To retrieve the file system path for the specified section of a GPO, you can call the
[GetFileSysPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getfilesyspath) method.

## See also

[GetFileSysPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igpeinformation-getfilesyspath)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGPEInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igpeinformation)