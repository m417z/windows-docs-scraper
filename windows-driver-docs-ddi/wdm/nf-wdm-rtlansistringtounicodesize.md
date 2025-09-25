# RtlAnsiStringToUnicodeSize macro

## Description

The **RtlAnsiStringToUnicodeSize** routine returns the number of bytes required to hold an ANSI string converted into a Unicode string.

## Parameters

### `STRING` [in]

Pointer to a buffer containing the ANSI string.

## Syntax

```cpp
//
//  NTSYSAPI
//  ULONG
//  NTAPI
//  RtlAnsiStringToUnicodeSize(
//      PANSI_STRING AnsiString
//      );
//

#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    RtlxAnsiStringToUnicodeSize(STRING)                      \
)

```

## Remarks

**RtlAnsiStringToUnicodeSize** returns a ULONG value containing the number of bytes required to hold an ANSI string converted into a Unicode string.

Casting the return value of the **RtlAnsiStringToUnicodeSize** routine to USHORT might cause a loss of data. To avoid potential problems, callers of this routine should test the return value for arithmetic overflow. Note that **RtlAnsiStringToUnicodeSize** accounts for the trailing **NULL**.

Callers of **RtlAnsiStringToUnicodeSize** must be running at IRQL = PASSIVE_LEVEL.

## See also

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlxAnsiStringToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlxansistringtounicodesize)