# IVBFormat::Format

## Description

Formats a string according to a pattern.

**Note** The use of this method is no longer recommended because containers other than Visual Basic do not support
it.

## Parameters

### `vData` [in]

Data to be formatted.

### `bstrFormat` [in]

Format string to be applied to the data.

### `lpBuffer` [in]

Pointer to result buffer.

### `cb` [in]

Length of result buffer.

### `lcid` [in]

Locale ID.

### `sFirstDayOfWeek` [in]

Affects the 'w', FirstDayOfWeek, format result.

| Value | Meaning |
| --- | --- |
| **vbUseSystem** | Use the **FirstWeekday** setting in the host UI. If no host value is provided, use the current system value from the NLS API. |
| **vbSunday** | Sunday |
| **vbMonday** | Monday |
| **vbTuesday** | Tuesday |
| **vbWednesday** | Wednesday |
| **vbThursday** | Thursday |
| **vbFriday** | Friday |
| **vbSaturday** | Saturday |

### `sFirstWeekOfYear` [in]

Affects the 'ww', FirstWeekOfYear, format result.

| Value | Meaning |
| --- | --- |
| **vbUseSystem** | Use the **FirstWeekOfYear** setting in the host UI. If no host value is provided, use the current system value from the NLS API. |
| **vbFirstJan1** | Start on January 1 (default). |
| **vbFirstFourDays** | Start with the first four-day week. |
| **vbFirstFullWeek** | Start with the first full week. |

### `rcb` [out]

Number of bytes copied to the result buffer.

## Return value

This method supports the standard return values **E_INVALIDARG**,
**E_OUTOFMEMORY**, and **E_UNEXPECTED**, as well as the
following:

## Remarks

When migrating a VBX control to an OLE control,
**Format** replaces the Visual Basic
**VBFormat**, which is no longer supported.

## See also

[IVBFormat](https://learn.microsoft.com/windows/desktop/api/vbinterf/nn-vbinterf-ivbformat)