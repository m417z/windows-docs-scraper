# SnmpUtilIdsToA function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilIdsToA** function converts an object identifier (OID) to a null-terminated string. This function is an element of the SNMP Utility API.

## Parameters

### `Ids` [in]

Pointer to an array of unsigned integers. The array contains the sequence of numbers that the OID contains. The *IdLength* parameter specifies the array's length.

For more information, see the following Return Values and Remarks sections.

### `IdLength` [in]

Specifies the number of elements in the array pointed to by the *Ids* parameter.

## Return value

The function returns a null-terminated string that contains the string representation of the array of numbers pointed to by the *Ids* parameter. The string contains a sequence of numbers separated by periods ('.'); for example, 1.3.6.1.4.1.311.

If the *Ids* parameter is null, or if the *IdLength* parameter specifies zero, the function returns the string "\<null oid>".

The maximum length of the returned string is 256 characters. If the string's length exceeds 256 characters, the string is truncated and terminated with a sequence of three periods ('...').

## Remarks

The
**SnmpUtilIdsToA** function can assist with the debugging of SNMP applications.

Note that the following memory restrictions apply when you call
**SnmpUtilIdsToA**:

* The *Ids* parameter must point to a valid memory block of at least *IdLength* integers, or the function call results in an access violation exception.
* The string returned by
  **SnmpUtilIdsToA** resides in memory that the SNMP Utility API allocates. The application should not make any assumptions about the memory allocation. The data is guaranteed to be valid until you call
  **SnmpUtilIdsToA** again, so before calling the function again you should copy the data to another location.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOidToA](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidtoa)