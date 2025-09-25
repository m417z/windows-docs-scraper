# SnmpDecodeMsg function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpDecodeMsg** function decodes an encoded SNMP message into its components. This function performs the opposite action of the WinSNMP
[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg) function.

## Parameters

### `session` [in]

Handle to the WinSNMP session. This parameter is required. For additional information, see the following Remarks section.

### `srcEntity` [out]

Pointer to a variable that receives a handle to the source management entity. For more information, see the following Remarks section.

### `dstEntity` [out]

Pointer to a variable that receives a handle to the target management entity. For more information, see the following Remarks section.

### `context` [out]

Pointer to a variable that receives a handle to the context (a set of managed object resources) that the target management entity controls.

### `pdu` [out]

Pointer to a variable that receives a handle to the SNMP protocol data unit (PDU).

### `msgBufDesc` [in]

Pointer to an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure that contains the SNMP message to decode into its components. The **len** member of the structure specifies the maximum number of bytes to process; the **ptr** member points to the encoded SNMP message.

## Return value

If the function succeeds, the return value is the number of decoded bytes. This value can be equal to, or less than, the **len** member of the
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure pointed to by the *msgBufDesc* parameter.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
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
| **SNMPAPI_OUTPUT_TRUNCATED** | The output buffer length is insufficient. No output parameters were created. |
| **SNMPAPI_MESSAGE_INVALID** | The SNMP message format in the buffer indicated by the *msgBufDesc* parameter is invalid. No output parameters were created. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The Microsoft WinSNMP implementation returns a value of zero in the *srcEntity* and the *dstEntity* parameters when an application submits an SNMPv1 or an SNMPv2C message to the
**SnmpDecodeMsg** function. This is because the message format does not include the address information necessary to create WinSNMP entity resources.

The Microsoft WinSNMP implementation allocates resources to the WinSNMP application as a result of a successful call to the
**SnmpDecodeMsg** function. It is recommended that the WinSNMP application free individual resources with the WinSNMP function that corresponds to the resource. For additional information, see
[Freeing WinSNMP Descriptors](https://learn.microsoft.com/windows/desktop/SNMP/freeing-winsnmp-descriptors) and
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg)

[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext)

[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity)

[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets)