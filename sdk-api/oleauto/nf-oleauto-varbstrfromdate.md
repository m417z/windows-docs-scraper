# VarBstrFromDate function

## Description

Converts a date value to a BSTR value.

## Parameters

### `dateIn` [in]

The value to convert.

### `lcid` [in]

The locale identifier.

### `dwFlags` [in]

One or more of the following flags.

| Value | Meaning |
| --- | --- |
| **LOCALE_NOUSEROVERRIDE** | Uses the system default locale settings, rather than custom locale settings. |
| **VAR_CALENDAR_HIJRI** | If set then the Hijri calendar is used. Otherwise the calendar set in the control panel is used. |
| **VAR_CALENDAR_THAI** | If set then the Buddhist year is used. |
| **VAR_CALENDAR_GREGORIAN** | If set the Gregorian year is used. |
| **VAR_FOURDIGITYEARS** | Use 4-digit years instead of 2-digit years. |
| **VAR_TIMEVALUEONLY** | Omits the date portion of a VT_DATE and returns only the time. Applies to conversions to or from dates. |
| **VAR_DATEVALUEONLY** | Omits the time portion of a VT_DATE and returns only the date. Applies to conversions to or from dates. |

### `pbstrOut` [out]

The resulting value.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADVARTYPE** | The input parameter is not a valid type of variant. |
| **DISP_E_OVERFLOW** | The data pointed to by the output parameter does not fit in the destination type. |
| **DISP_E_TYPEMISMATCH** | The argument could not be coerced to the specified type. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |