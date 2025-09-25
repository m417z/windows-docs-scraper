# _DXGKARG_QUERYDIAGNOSTICTYPESSUPPORT structure

## Description

Arguments for the [DxgkddiQueryDiagnosticTypesSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydiagnostictypessupport) callback function.

## Members

### `DiagnosticCategory` [in]

A [DXGK_DIAGNOSTIC_CATEGORIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_categories) structure that indicates which one of the diagnostic categories the supported types are being queried for.

### `NoninvasiveTypes` [out]

A [DXGK_DIAGNOSTIC_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_types) structure that indicates driver support for diagnostics, which can be achieved without significant overhead or impact on the system. Noninvasive diagnostics should be sufficiently benign that they may be enabled by the OS to proactively gather telemetry.

### `InvasiveTypes` [out]

A [DXGK_DIAGNOSTIC_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_types) structure that indicates driver support for diagnostics, which the driver supports but may require significant overhead or have significant impact on the system. Invasive diagnostics will only be enabled when required to gather information for specific investigations and are expected to have power and/or performance drawbacks making them unsuitable for automated usage.