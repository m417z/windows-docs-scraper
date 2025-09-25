# smiOCTETS structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**smiOCTETS** structure passes context strings to multiple WinSNMP functions. The structure also describes and receives encoded SNMP messages.

The
**smiOCTETS** structure contains a pointer to an SNMP octet string of variable length. The structure can be a member of the
[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue) structure.

## Members

### `len`

Specifies an unsigned long integer value that indicates the number of bytes in the octet string array pointed to by the **ptr** member.

### `ptr`

Pointer to a byte array that contains the octet string of interest. A **NULL**-terminating byte is not required.

## Remarks

The Microsoft WinSNMP implementation allocates and deallocates memory for all output
**smiOCTETS** structures. The WinSNMP application should not free memory that the implementation allocates for the **ptr** member of an
**smiOCTETS** structure. Instead, the application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to free the memory.

Because the WinSNMP application allocates memory for input descriptor objects with variable lengths, it must free that memory. For more information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpContextToStr](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcontexttostr)

[SnmpDecodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpdecodemsg)

[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg)

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[SnmpStrToContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtocontext)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[WinSNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-structures)

[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue)