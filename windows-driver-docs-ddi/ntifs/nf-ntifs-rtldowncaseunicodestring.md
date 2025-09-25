# RtlDowncaseUnicodeString function

## Description

The **RtlDowncaseUnicodeString** routine converts the specified Unicode source string to lowercase. The translation conforms to the current system locale information.

## Parameters

### `DestinationString`

Pointer to a caller-allocated buffer to receive the converted Unicode string. If *AllocateDestinationString* is **FALSE**, the caller must also allocate a buffer for the **Buffer** member of *DestinationString* to hold the Unicode data. If *AllocateDestinationString* is **TRUE**, **RtlDowncaseUnicodeString** allocates a buffer large enough to hold the string, passes a pointer to it in **Buffer**, and updates the length and maximum length members of *DestinationString* accordingly.

### `SourceString` [in]

Pointer to the source Unicode string to be converted to lowercase.

### `AllocateDestinationString` [in]

Set to **TRUE** if **RtlDowncaseUnicodeString** should allocate the buffer space for the *DestinationString*, **FALSE** otherwise. If this parameter is **TRUE**, the caller is responsible for freeing the buffer when it is no longer needed by calling **RtlFreeUnicodeString**.

## Return value

If the operation succeeds, **RtlDowncaseUnicodeString** returns STATUS_SUCCESS. Otherwise, no storage was allocated and no conversion was done.

## Remarks

If caller sets *AllocateDestinationString* to **TRUE**, **RtlDowncaseUnicodeString** replaces the **Buffer** member of *DestinationString* with a pointer to the buffer it allocates. The old value can be overwritten even when the routine returns an error status code.

**RtlDowncaseUnicodeString** does not modify the source string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[RtlUpcaseUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlupcaseunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)