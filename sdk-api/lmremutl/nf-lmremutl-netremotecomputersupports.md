# NetRemoteComputerSupports function

## Description

The
**NetRemoteComputerSupports** function queries the redirector to retrieve the optional features the remote system supports. Features include Unicode, Remote Procedure Call (RPC), and Remote Administration Protocol support. The function establishes a network connection if one does not exist.

## Parameters

### `UncServerName` [in]

Pointer to a constant string that specifies the name of the remote server to query. If this parameter is **NULL**, the local computer is used.

### `OptionsWanted` [in]

Specifies a value that contains a set of bit flags indicating the features of interest. This parameter must be at least one of the following values.

| Value | Meaning |
| --- | --- |
| **SUPPORTS_REMOTE_ADMIN_PROTOCOL** | Requests Remote Administration Protocol support. |
| **SUPPORTS_RPC** | Requests RPC support. |
| **SUPPORTS_SAM_PROTOCOL** | Requests Security Account Manager (SAM) support. |
| **SUPPORTS_UNICODE** | Requests Unicode standard support. |
| **SUPPORTS_LOCAL** | Requests support for the first three values listed in this table. If UNICODE is defined by the calling application, requests the four features listed previously. |

### `OptionsSupported` [out]

Pointer to a value that receives a set of bit flags. The flags indicate which features specified by the *OptionsWanted* parameter are implemented on the computer specified by the *UncServerName* parameter. (All other bits are set to zero.)

The value of this parameter is valid only when the
**NetRemoteComputerSupports** function returns NERR_Success.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Either the *OptionsWanted* parameter or the *OptionsSupported* parameter is **NULL**; both parameters are required. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |

## Remarks

No special group membership is required to successfully execute the
**NetRemoteComputerSupports** function.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Remote
Utility Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/remote-utility-functions)