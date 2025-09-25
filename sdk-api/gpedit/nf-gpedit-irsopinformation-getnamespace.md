# IRSOPInformation::GetNamespace

## Description

The
**GetNameSpace** method retrieves the namespace from which the RSoP data is being displayed.

## Parameters

### `dwSection` [in]

Specifies the GPO section. This parameter can be one of the following values.

#### GPO_SECTION_ROOT

Root section

#### GPO_SECTION_USER

User section

#### GPO_SECTION_MACHINE

Computer section

### `pszName` [out]

Receives the namespace from which the RSoP data is being displayed. The computer and user RSoP data are in sub-namespaces under this namespace. Computer RSoP data is under the Computer sub-namespace, and user RSoP data is under the User sub-namespace.

### `cchMaxLength` [in]

Specifies the size, in characters, of the *pszName* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IRSOPInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-irsopinformation)