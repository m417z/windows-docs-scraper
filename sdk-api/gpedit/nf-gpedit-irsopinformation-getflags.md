# IRSOPInformation::GetFlags

## Description

The
**GetFlags** method retrieves information about the RSoP user interface session.

## Parameters

### `pdwFlags` [out]

Receives a pointer to a value that contains information about the RSoP session. This parameter can be the following value.

#### RSOP_INFO_FLAG_LOGGING_MODE

If this value is specified, the RSoP session is in logging mode. If this value is not specified, it indicates that the session is in planning mode.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IRSOPInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-irsopinformation)