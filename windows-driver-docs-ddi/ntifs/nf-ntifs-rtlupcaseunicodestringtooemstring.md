# RtlUpcaseUnicodeStringToOemString function

## Description

The **RtlUpcaseUnicodeStringToOemString** routine translates a given Unicode source string into an uppercase OEM string using the current system OEM code page.

## Parameters

### `DestinationString`

Pointer to a caller-allocated buffer to receive the counted OEM string. If *AllocateDestinationString* is **FALSE**, the caller must also allocate a buffer for the **Buffer** member of *DestinationString* to hold the OEM data. If *AllocateDestinationString* is **TRUE**, **RtlUpcaseUnicodeStringToOemString** allocates a buffer large enough to hold the string, passes a pointer to it in **Buffer**, and updates the length and maximum length members of *DestinationString* accordingly.

### `SourceString` [in]

Pointer to the Unicode string to be translated.

### `AllocateDestinationString` [in]

Set to **TRUE** if **RtlUpcaseUnicodeStringToOemString** should allocate the buffer space for the *DestinationString*, **FALSE** otherwise. If this parameter is **TRUE**, the caller is responsible for freeing the buffer when it is no longer needed by calling **RtlFreeOemString**.

## Return value

**RtlUpcaseUnicodeStringToOemString** returns STATUS_SUCCESS if the string at *DestinationString* is translated. Otherwise, no storage was allocated, nor was any conversion performed.

## Remarks

**RtlUpcaseUnicodeStringToOemString** translates the given source string using the OEM code page that was installed as the current system code page at system boot time, and converts the OEM string to uppercase.

This routine can substitute a default character in the destination string for all source string characters that it cannot map to the current code page and, then, return STATUS_SUCCESS.

This routine does not modify the source string. It returns a null-terminated OEM string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlFreeOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfreeoemstring)

[RtlUnicodeStringToCountedOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtocountedoemstring)

[RtlUnicodeStringToOemSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemsize)

[RtlUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemstring)

[RtlUpcaseUnicodeToOemN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodetooemn)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)