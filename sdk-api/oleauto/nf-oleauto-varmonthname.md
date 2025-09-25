# VarMonthName function

## Description

Returns a string containing the localized month name.

## Parameters

### `iMonth` [in]

Represents the month, as a number from 1 to 12.

### `fAbbrev` [in]

If zero then the full (non-abbreviated) month name is used. If non-zero, then the abbreviation for the month name is used.

### `dwFlags` [in]

VAR_CALENDAR_HIJRI is the only flag that can be set.

### `pbstrOut` [out]

Receives the formatted string that represents the variant.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |