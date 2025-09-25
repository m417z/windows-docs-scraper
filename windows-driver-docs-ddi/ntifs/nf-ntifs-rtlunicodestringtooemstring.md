# RtlUnicodeStringToOemString function

## Description

The **RtlUnicodeStringToOemString** routine translates a given Unicode source string into an OEM string using the current system OEM code page.

## Parameters

### `DestinationString`

Pointer to a caller-allocated buffer to receive the OEM string. If *AllocateDestinationString* is **FALSE**, the caller must also allocate a buffer for the **Buffer** member of *DestinationString* to hold the OEM data. If *AllocateDestinationString* is **TRUE**, **RtlUnicodeStringToOemString** allocates a buffer large enough to hold the string, passes a pointer to it in **Buffer**, and updates the length and maximum length members of *DestinationString* accordingly.

### `SourceString` [in]

Pointer to the Unicode string to be translated.

### `AllocateDestinationString` [in]

Set to **TRUE** if **RtlUnicodeStringToOemString** should allocate the buffer space for the *DestinationString*, **FALSE** otherwise. If this parameter is **TRUE**, the caller is responsible for freeing the buffer when it is no longer needed by calling **RtlFreeOemString**.

## Return value

**RtlUnicodeStringToOemString** returns STATUS_SUCCESS if the string at *DestinationString* is translated. Otherwise, no storage was allocated, and no conversion was performed.

## Remarks

**RtlUnicodeStringToOemString** translates the given source string using the OEM code page that was installed as the current system code page at system boot time.

**RtlUnicodeStringToOemString** does not modify the source string. It returns a null-terminated OEM string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlFreeOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfreeoemstring)

[RtlUnicodeStringToCountedOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtocountedoemstring)

[RtlUnicodeStringToOemSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemsize)

[RtlUnicodeToOemN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetooemn)

[RtlUpcaseUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtooemstring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)