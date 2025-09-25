# RtlIsNameLegalDOS8Dot3 function

## Description

The **RtlIsNameLegalDOS8Dot3** routine determines whether a given name represents a valid short (8.3) file name.

## Parameters

### `Name` [in]

Pointer to a Unicode string containing the file name.

### `OemName` [in, out]

Pointer to an optional caller-allocated buffer that receives a counted OEM string corresponding to the Unicode string at *Name*.

### `NameContainsSpaces` [out, optional]

Pointer to an optional BOOLEAN value that receives **TRUE** if the string at *Name* contains embedded spaces, **FALSE** otherwise. This value is valid only if **RtlIsNameLegalDOS8Dot3** returns **TRUE**.

## Return value

**RtlIsNameLegalDOS8Dot3** returns **TRUE** if the string at *Name* is a legal short (8.3) file name, **FALSE** otherwise.

## Remarks

**RtlIsNameLegalDOS8Dot3** translates the Unicode string at *Name* using the OEM code page that was installed as the current system code page at system boot time, and converts the translated string to uppercase. (If the caller supplied a buffer at *OemName*, this buffer receives the resulting string.) **RtlIsNameLegalDOS8Dot3** checks that the name is a properly formatted 8.3 name and contains only legal characters.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

If the block of memory at *Name* is nonpaged, the caller can be running at IRQL <= DISPATCH_LEVEL. Otherwise, callers of **RtlIsNameLegalDOS8Dot3** must be running at IRQL < DISPATCH_LEVEL.

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlGenerate8dot3Name](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgenerate8dot3name)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)