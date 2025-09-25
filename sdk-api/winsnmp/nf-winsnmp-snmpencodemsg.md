# SnmpEncodeMsg function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft WinSNMP implementation uses the parameters passed in the WinSNMP
**SnmpEncodeMsg** function to encode an SNMP message. The implementation returns the encoded SNMP message to the WinSNMP application in the buffer specified by the *msgBufDesc* parameter.

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `srcEntity` [in]

Handle to the management entity that initiates the request to encode the SNMP message.

### `dstEntity` [in]

Handle to the target management entity.

### `context` [in]

Handle to the context (a set of managed object resources) that the target management entity controls.

### `pdu` [in]

Handle to the PDU that contains the SNMP operation request.

### `msgBufDesc` [out]

Pointer to an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure that receives the encoded SNMP message.

## Return value

If the function succeeds, the return value is the length, in bytes, of the encoded SNMP message. This number is also the value of the **len** member of the
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure pointed to by the *msgBufDesc* parameter.

If the function fails, the return value is SNMPAPI_FAILURE. For additional information, see the following Remarks section. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The *session* parameter is invalid. |
| **SNMPAPI_ENTITY_INVALID** | One or both of the entity parameters is invalid. |
| **SNMPAPI_CONTEXT_INVALID** | The *context* parameter is invalid. |
| **SNMPAPI_PDU_INVALID** | The *pdu* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The first five parameters passed to the
**SnmpEncodeMsg** function are the same parameters that are passed to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function.

The WinSNMP application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to free resources allocated for the **ptr** member of the
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure. This is the structure pointed to by the *msgBufDesc* parameter. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

On input, the
**SnmpEncodeMsg** function ignores the members of the structure pointed to by the *msgBufDesc* parameter. The implementation overwrites the members of the structure if the function completes successfully.

The implementation verifies the format of the first five input parameters. If one of the parameters is invalid,
**SnmpEncodeMsg** returns SNMPAPI_FAILURE, and
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) returns an extended error code.

## See also

[SnmpDecodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpdecodemsg)

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets)