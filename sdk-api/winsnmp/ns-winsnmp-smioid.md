# smiOID structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**smiOID** structure passes object identifiers to multiple WinSNMP functions. The structure also receives the variable name of a variable binding entry in a call to the
[SnmpGetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvb) function.

The
**smiOID** structure contains a pointer to a variable length array of a named object's subidentifiers. The structure can be a member of the
[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue) structure.

## Members

### `len`

Specifies an unsigned long integer value that indicates the number of elements in the array pointed to by the **ptr** member.

### `ptr`

Pointer to an array of unsigned long integers that represent the object identifier's subidentifiers.

## Remarks

In an
**smiOID** structure, the format of the array pointed to by the **ptr** member is one subidentifier per array element. For example, the string "1.3.6.1" would be an array of four elements {1,3,6,1}.

The Microsoft WinSNMP implementation allocates and deallocates memory for all output
**smiOID** structures. The WinSNMP application should not free memory that the implementation allocates for the **ptr** member of an
**smiOID** structure. Instead, the application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to free the memory.

Because the WinSNMP application allocates memory for input descriptor objects with variable lengths, it must free that memory. For more information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[SnmpGetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvb)

[SnmpOidCompare](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpoidcompare)

[SnmpOidCopy](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpoidcopy)

[SnmpOidToStr](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpoidtostr)

[SnmpStrToOid](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtooid)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[WinSNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-structures)

[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue)