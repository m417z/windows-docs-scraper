# RtlInitUnicodeString function

## Description

For more information, see the [WdmlibRtlInitUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibrtlinitunicodestringex) function.

## Parameters

### `DestinationString` [out]

For more information, see the [WdmlibRtlInitUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibrtlinitunicodestringex) function.

### `SourceString` [in, optional]

For more information, see the [WdmlibRtlInitUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibrtlinitunicodestringex) function.

## Return value

For more information, see the [WdmlibRtlInitUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibrtlinitunicodestringex) function.

## Remarks

The **RTL_CONSTANT_STRING** macro creates a string or Unicode string structure to hold a counted string.

```
STRING RTL_CONSTANT_STRING(
  [in]  PCSZ SourceString
);

UNICODE_STRING RTL_CONSTANT_STRING(
  [in]  PCWSTR SourceString
);
```

**RTL_CONSTANT_STRING** returns either a string structure or Unicode string structure.

The **RTL_CONSTANT_STRING** macro replaces the [RtlInitAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitansistring), [RtlInitString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitstring), and **RtlInitUnicodeString** routines when passing a constant string.

You can use **RTL_CONSTANT_STRING** to initialize global variables.

## See also

[RtlUnicodeStringInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringinit)

[RtlUnicodeStringInitEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringinitex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdmlibRtlInitUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibrtlinitunicodestringex)