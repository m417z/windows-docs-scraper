# GetIScsiVersionInformation function

## Description

The **GetIscsiVersionInformation** function retrieves information about the initiator version.

## Parameters

### `VersionInfo`

Pointer to an [ISCSI_VERSION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_version_info) structure that contains initiator version information.

## Return value

Returns **ERROR_SUCCESS** if the operation is successful. If the operation fails due to a socket connection error, this function will return a Winsock error code.

## See also

[ISCSI_VERSION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_version_info)