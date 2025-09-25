# _DXGK_DIAGNOSTIC_TYPES structure

## Description

A structure that contains a union of all the defined sets of diagnostic types. The member of the union which should be used to interpret this data is determined by the bit-field which is set in the associated [DXGK_DIAGNOSTIC_CATEGORIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_categories) structure. In general, there will be one set of diagnostic types for each diagnostic category.

## Members

### `Notifications`

A [DXGK_DIAGTYPE_NOTIFICATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagtype_notifications) structure for indicating what kind of diagnostics are being described.

### `Progressions`

A [DXGK_DIAGTYPE_PROGRESSIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagtype_progressions) structure for indicating a Progressions diagnostic type.

### `Value`

Value of the diagnostic type.

## Remarks

The DXGK_DIAGNOSTIC_TYPES structure is used to identify diagnostic types in different scenarios. \ Depending on the context, zero, one or multiple bits may be set. When reporting a diagnostic, exactly one bit must be set. When controlling diagnostics or querying support, multiple bits may be set and zero bits can be a valid value, for example, when the OS calls [DxgkDdiControlDiagnosticReporting](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_controldiagnosticreporting) to disable all reporting.