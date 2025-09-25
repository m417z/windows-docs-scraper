# SnmpOidCompare function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpOidCompare** function lexicographically compares two SNMP object identifiers, up to the length specified by the *maxlen* parameter.

## Parameters

### `xOID` [in]

Pointer to the first
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) object identifier to compare. The length of the object identifier can be zero.

### `yOID` [in]

Pointer to the second
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) object identifier to compare. The length of the object identifier can be zero.

### `maxlen` [in]

If not equal to zero, specifies the number of subidentifiers to compare. This parameter must be less than MAXOBJIDSIZE: 128 subidentifiers, the maximum number of components in an object identifier. For additional information, see the following Remarks section.

### `result` [out]

Pointer to an integer variable to receive the result of the comparison. The variable can receive one of the following results.

| Result | Meaning |
| --- | --- |
| **Greater than 0** | *xOID* is greater than *yOID* |
| **Equal to 0** | *xOID* equals *yOID* |
| **Less than 0** | *xOID* is less than *yOID* |

For additional comparison conditions, see the following Remarks section.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OID_INVALID** | One or both of the *xOID* and *yOID* parameters is invalid. |
| **SNMPAPI_SIZE_INVALID** | The *maxlen* parameter is invalid. The parameter size is greater than MAXOBJIDSIZE. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

A WinSNMP application can call the
**SnmpOidCompare** function to determine whether two object identifiers have common prefixes.

If the *maxlen* parameter is not equal to zero, and not greater than MAXOBJIDSIZE, the value of *maxlen* sets the upper limit for the number of subidentifiers to compare. The maximum number of subidentifiers that the
**SnmpOidCompare** function compares defaults to whichever is the smallest number—the *maxlen* parameter, or the **len** member of one of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structures pointed to by the *xOID* and *yOID* parameters.

If the *maxlen* parameter is equal to zero, the maximum number of subidentifiers that the
**SnmpOidCompare** function compares defaults to the number that is the smaller of the **len** members of the two
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structures.

The value of the *result* parameter will indicate that *xOID* equals *yOID* if the two
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structures are lexicographically equal and one of the following occurs:

* **SnmpOidCompare** compares a *maxlen* number of subidentifiers.
* **SnmpOidCompare** compares the maximum number of subidentifiers, and the **len** members of both
  [smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structures are equal, but less than the *maxlen* parameter.

## See also

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)