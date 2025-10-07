# SET structure

The **SET** structure defines a set of values.

## Members

**nEntries**

Total number of entries in a set.

**lpByteTable**

Pointer to an array of BYTE values.

**lpWordTable**

Pointer to an array of WORD values.

**lpDwordTable**

Pointer to an array of DWORD values.

**lpLargeIntTable**

Pointer to an array of [LARGEINT](https://learn.microsoft.com/windows/win32/netmon2/largeint) structures.

**lpSystemTimeTable**

Pointer to an array of SYSTEMTIME values.

**lpLabeledByteTable**

Pointer to an array of [LABELED\_BYTE](https://learn.microsoft.com/windows/win32/netmon2/labeled-byte) structures. Each **LABELED\_BYTE** structure defines a value and label. Network Monitor displays a label if it finds a corresponding value in the protocol packet.

**lpLabeledWordTable**

Pointer to an array of [LABELED\_WORD](https://learn.microsoft.com/windows/win32/netmon2/labeled-word) structures that define a set of WORD values and labels.

**lpLabeledDwordTable**

Pointer to an array of [LABELED\_DWORD](https://learn.microsoft.com/windows/win32/netmon2/labeled-dword) structures that define a set of DWORD values and labels.

**lpLabeledLargeIntTable**

Pointer to an array of [LABELED\_LARGEINT](https://learn.microsoft.com/windows/win32/netmon2/labeled-largeint) structures that define a set of LARGEINT values and labels.

**lpLabeledSystemTimeTable**

Pointer to an array of [LABELED\_SYSTEMTIME](https://learn.microsoft.com/windows/win32/netmon2/labeled-systemtime) structures that define a set of SYSTEM values and labels.

**lpLabeledBit**

Pointer to an array of [LABELED\_BIT](https://learn.microsoft.com/windows/win32/netmon2/labeled-bit) structures that define a set of labeled BIT pairs. Each BIT can specify two labels one label for each state (0 or 1) of the BIT.

**lpVoidTable**

Pointer to an array of values.

## Remarks

The **SET** structure is used to define a set of comparison data that Network Monitor can use to interpret the value of a property in a protocol packet. When a set of comparison data is required, a pointer to the **SET** structure is specified in the **lpSet** member of the [PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo) structure.

The parser DLL can provide a value set and a label set. The member of the **UNION** that you select in a **SET** structure points to an array of structures that define each member of a set.

- Value set

 A value set is used when you want Network Monitor to include an in-set or not-in-set indicator with the value found in the protocol packet. For example, if a DWORD set is specified, Network Monitor displays a label for each DWORD value found in the protocol packet, indicating that the DWORD is or is not specified in the set.

 A value set can be based on BYTE, WORD, DWORD, LARGEINT, and SYSTEMTIME data types.

- Label set

 A label set is used when you want Network Monitor to display a user-defined label instead of the property values specified in a set.

 A label set can be based on BYTE, WORD, DWORD, LARGEINT, SYSTEMTIME and BIT label pairs.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[LABELED\_BIT](https://learn.microsoft.com/windows/win32/netmon2/labeled-bit)

[PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo)

