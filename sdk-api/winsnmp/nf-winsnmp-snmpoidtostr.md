# SnmpOidToStr function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpOidToStr** function converts the internal binary representation of an SNMP object identifier to its dotted numeric string format, for example, to "1.2.3.4.5.6".

## Parameters

### `srcOID` [in]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure with an object identifier to convert.

### `size` [in]

Specifies the size, in bytes, of the buffer indicated by the *string* parameter. For more information, see the following Remarks section.

### `string` [out]

Pointer to a buffer to receive the converted string object identifier that specifies the SNMP management entity.

## Return value

If the function succeeds, the return value is the length, in bytes, of the string that the WinSNMP application writes to the *string* parameter. The return value includes a **null**-terminating byte. This value may be less than or equal to the value of the *size* parameter, but it may not be greater.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SIZE_INVALID** | The *size* parameter is invalid. This parameter cannot be equal to zero; it must indicate the size of the buffer pointed to by the *string* parameter. |
| **SNMPAPI_OID_INVALID** | The *srcOID* parameter is invalid. For additional information, see the following Remarks section. |
| **SNMPAPI_OUTPUT_TRUNCATED** | The output buffer length is insufficient. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

It is recommended that a WinSNMP application specify, with the *size* parameter, a string buffer of MAXOBJIDSTRSIZE length (1408 bytes). This ensures that the output buffer is large enough to hold the converted string. Because the converted string is usually less than MAXOBJIDSTRSIZE, the WinSNMP application can copy the converted string to a smaller buffer. The application can then reuse or free the memory that it allocated for the initial buffer. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpStrToOid](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtooid)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)