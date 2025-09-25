## Description

The **RtlInitString** routine initializes a counted string of 8-bit characters.

## Parameters

### `DestinationString` [out]

A pointer to the **STRING** structure to be initialized. The Ntdef.h header file defines this structure to be identical to the [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure.

### `SourceString` [in, optional]

A pointer to a null-terminated character string. This string is used to initialize the counted string pointed to by *DestinationString*.

## Return value

## Remarks

This routine initializes a counted character string.

The routine copies the *SourceString* pointer value to the **Buffer** member of the **STRING** structure pointed to by *DestinationString*. The **Length** member of this structure is set to the length, in bytes, of the source string, excluding the terminating null. The **MaximumLength** member of the structure is set to the length, in bytes, of the source string, including the terminating null. If *SourceString* is **NULL**, **Length** and **MaximumLength** are both set to zero.

**RtlInitString** does not alter the source string pointed to by *SourceString*.

If the source string is longer than MAXUSHORT - 1 bytes, **RtlInitString** sets the **Length** member of the **STRING** structure pointed to by *DestinationString* to MAXUSHORT - 1, and sets the **MaximumLength** member of this structure to MAXUSHORT. In this case, the **Length** and **MaximumLength** values misrepresent the length of the null-terminated source string, and relying on the accuracy of these values is potentially dangerous.

Callers of **RtlInitString** can be running at IRQL <= DISPATCH_LEVEL if the *DestinationString* buffer is nonpageable. Usually, callers run at IRQL = PASSIVE_LEVEL because most other **Rtl*Xxx*String** routines cannot be called at IRQL > PASSIVE_LEVEL.

The **RTL_CONSTANT_STRING** macro creates a string or Unicode string structure to hold a counted string.

```cpp
STRING RTL_CONSTANT_STRING(
  [in]  PCSZ SourceString
);

UNICODE_STRING RTL_CONSTANT_STRING(
  [in]  PCWSTR SourceString
);
```

**RTL_CONSTANT_STRING** returns either a string structure or Unicode string structure.

The **RTL_CONSTANT_STRING** macro replaces the [RtlInitAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitansistring), **RtlInitString**, and [RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring) routines when passing a constant string.

You can use **RTL_CONSTANT_STRING** to initialize global variables.

## See also

[**ANSI_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)