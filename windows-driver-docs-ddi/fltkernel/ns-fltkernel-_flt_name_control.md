# _FLT_NAME_CONTROL structure

## Description

A minifilter that provides file names for the Filter Manager's name cache can use the FLT_NAME_CONTROL structure to manage its name buffers.

## Members

### `Name`

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the file name string.

## Remarks

Minifilters must not attempt to free or replace the buffer in the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that the **Name** member points to directly. Instead, minifilters should call [FltCheckAndGrowNameControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckandgrownamecontrol) to obtain a larger name control buffer.

## See also

[FltCheckAndGrowNameControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckandgrownamecontrol)

[FltGetFileNameFormat](https://learn.microsoft.com/previous-versions/ff543030(v=vs.85))

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetFileNameQueryMethod](https://learn.microsoft.com/previous-versions/ff543040(v=vs.85))

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)