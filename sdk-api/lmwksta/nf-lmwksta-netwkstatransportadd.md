# NetWkstaTransportAdd function

## Description

[This function is obsolete. To change the default settings for transport protocols manually, use the **Local Area Connection Properties** dialog box in the **Network and Dial-Up Connections** folder.]

Not supported.

The
**NetWkstaTransportAdd** function binds (or connects) the redirector to the transport. The redirector is the software on the client computer which generates file requests to the server computer.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string must begin with \\.

### `level` [in]

Specifies the information level of the data. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **0** | Specifies workstation transport protocol information. The *buf* parameter points to a [WKSTA_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_transport_info_0) structure. |

### `buf` [in]

Pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first parameter that causes the ERROR_INVALID_PARAMETER error. If this parameter is **NULL**, the index is not returned on error.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The level parameter, which indicates what level of data structure information is available, is invalid. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. |

## Remarks

Only members of the Administrators local group can successfully execute the
**NetWkstaTransportAdd** function.

If the
**NetWkstaTransportAdd** function returns ERROR_INVALID_PARAMETER, you can use the *parm_err* parameter to indicate the member of the
**WKSTA_TRANSPORT_INFO_0** structure that is invalid. The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error.

| Value | Member |
| --- | --- |
| TRANSPORT_QUALITYOFSERVICE_PARMNUM | **wkti0_quality_of_service** |
| TRANSPORT_NAME_PARMNUM | **wkti0_transport_name** |