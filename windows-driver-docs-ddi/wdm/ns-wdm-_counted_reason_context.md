# _COUNTED_REASON_CONTEXT structure (wdm.h)

## Description

The **COUNTED_REASON_CONTEXT** structure contains one or more strings that give reasons for a power request.

## Members

### `Version`

The version number of the structure. Set this member to DIAGNOSTIC_REASON_VERSION.

### `Flags`

Indicates whether the structure contains a simple reason string or a detailed set of reason strings. Set this member to one of the following constants:

* DIAGNOSTIC_REASON_SIMPLE_STRING
* DIAGNOSTIC_REASON_DETAILED_STRING

If **Flags** = DIAGNOSTIC_REASON_SIMPLE_STRING, the **SimpleString** member of the union is valid. If **Flags** = DIAGNOSTIC_REASON_DETAILED_STRING, the **ResourceFileName**, **ResourceReasonId**, **StringCount**, and **ReasonStrings** members are valid (and the **SimpleString** member is not valid).

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ResourceFileName`

A pointer to a wide-character, null-terminated string that contains the pathname of a resource file. This resource file contains one or more localized strings that give reasons for a power request. This member is optional and can be specified as **NULL** or as an empty string if no resource file is required. This member is valid only if **Flags** = DIAGNOSTIC_REASON_DETAILED_STRING.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ResourceReasonId`

The resource ID assigned to the first reason string in the resource file that is specified by **ResourceFileName**. This member is valid only if **Flags** = DIAGNOSTIC_REASON_DETAILED_STRING.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.StringCount`

The number of reason strings in the **ReasonStrings** array or in the resource file that is specified by **ResourceFileName**. This member is valid only if **Flags** = DIAGNOSTIC_REASON_DETAILED_STRING.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReasonStrings`

A pointer to an array of string pointers. Each array element is a pointer to a wide-character, null-terminated string. The number of array elements is specified by **StringCount**. This member is valid only if **Flags** = DIAGNOSTIC_REASON_DETAILED_STRING.

### `DUMMYUNIONNAME.SimpleString`

A pointer to a wide-character, null-terminated string that explains the reason for a power request. This member is valid only if **Flags** = DIAGNOSTIC_REASON_SIMPLE_STRING.

## Remarks

This structure is used by the [PoCreatePowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocreatepowerrequest) routine.

The [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) uses the reason string or strings contained in this structure as a diagnostic aid during functional and performance testing.

The **COUNTED_REASON_CONTEXT** structure can contain either a simple reason string or a set of detailed reason strings. If **Flags** = DIAGNOSTIC_REASON_SIMPLE_STRING, the **SimpleString** member points to a string that explains the reason for the power request. If **Flags** = DIAGNOSTIC_REASON_DETAILED_STRING, the **ResourceFileName**, **ResourceReasonId**, **StringCount**, and **ReasonStrings** members can give a detailed set of reasons for the power request.

The DIAGNOSTIC_REASON_DETAILED_STRING flag supports localization. If the localized resource file specified by **ResourceFileName** exists, the power manager retrieves the resource string specified by **ResourceReasonId** from the file and then formats the string, replacing `%1`, `%2`, etc. placeholders with corresponding items from the **ReasonStrings** array. Other format specifiers used with **FormatMessageW** are not supported.

The power manager retrieves the resource strings from [STRINGTABLE resources](https://learn.microsoft.com/windows/win32/menurc/stringtable-resource).

## See also

[PoCreatePowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocreatepowerrequest)