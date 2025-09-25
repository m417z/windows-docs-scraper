# SnmpMgrCtl function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrCtl** function sets an operating parameter associated with an SNMP session. This function is an element of the SNMP Management API.

## Parameters

### `session` [in]

Pointer to an internal structure that specifies the session to which the control code applies.

### `dwCtlCode` [in]

Specifies a value (a control code) that identifies the operation to perform.

Currently, MGMCTL_SETAGENTPORT is the only supported control code. Setting this code allows an SNMP management application to send requests to a remote agent that is "listening" for SNMP manager requests on an arbitrary port. For more information, see the *lpvInBuffer* and the *cbInBuffer* parameter descriptions.

### `lpvInBuffer` [in]

Pointer to the buffer that contains the input parameters required for the operation.

When you specify the MGMCTL_SETAGENTPORT control code, this parameter must point to an unsigned integer that specifies the port number on which the remote agent will "listen" for SNMP manager requests. The port number must be in host-byte order.

### `cbInBuffer` [in]

Specifies the size, in bytes, of the buffer pointed to by the *lpvInBuffer* parameter.

When you specify the MGMCTL_SETAGENTPORT control code, this parameter is equal to sizeof(UINT).

### `lpvOUTBuffer` [out]

Pointer to the buffer that receives the operation's output data.

### `cbOUTBuffer` [out]

Specifies the size, in bytes, of the buffer pointed to by the *lpvOutBuffer* parameter.

### `lpcbBytesReturned` [out]

Pointer to a variable that receives the actual size, in bytes, of the data stored in the buffer pointed to by the *lpvOutBuffer* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** can also return one of the following error codes.

| Return code | Description |
| --- | --- |
| **SNMP_MGMTAPI_INVALID_CTL** | The *dwCtlCode* parameter does not specify a valid control code. |
| **SNMP_MGMTAPI_INVALID_SESSION** | The *session* parameter does not specify a valid SNMP session. |
| **SNMP_MGMTAPI_INVALID_BUFFER** | One or more of the *lpvInBuffer*, *lpvOutBuffer*, or *lpcbBytesRequired* parameters are invalid, or the *cbInBuffer* or *cbOutBuffer* parameter is too small. |

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrOpen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgropen)