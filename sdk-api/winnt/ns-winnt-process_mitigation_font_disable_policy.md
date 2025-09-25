# PROCESS_MITIGATION_FONT_DISABLE_POLICY structure

## Description

Contains process mitigation policy settings for the loading of non-system fonts.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DisableNonSystemFonts`

Set (0x1) to prevent the process from loading non-system fonts; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditNonSystemFontLoading`

Set (0x1) to indicate that an Event Tracing for Windows (ETW) event should be logged when the process attempts to load a non-system font; leave unset (0x0) to indicate that an ETW event should not be logged.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

Reserved for system use.

## See also

[GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy)

[SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy)