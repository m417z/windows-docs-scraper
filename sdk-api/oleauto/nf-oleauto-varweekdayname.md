# VarWeekdayName function

## Description

Returns a string containing the localized name of the weekday.

## Parameters

### `iWeekday` [in]

The day of the week.

| Value | Meaning |
| --- | --- |
| 0 | The system default |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |
| 7 | Sunday |

### `fAbbrev` [in]

If zero then the full (non-abbreviated) weekday name is used. If non-zero, then the abbreviation for the weekday name is used.

### `iFirstDay` [in]

First day of the week.

| Value | Meaning |
| --- | --- |
| 0 | The system default |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |
| 7 | Sunday |

### `dwFlags` [in]

VAR_CALENDAR_HIJRI is the only flag that can be set.

### `pbstrOut` [out]

Receives the formatted string that represents the variant.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |