# _DXGKARG_CONTROLDIAGNOSTICREPORTING structure

## Description

Contains arguments for the call to [DxgkDdiControlDiagnosticReporting](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_controldiagnosticreporting).

## Members

### `DiagnosticCategory` [in]

A [DXGK_DIAGNOSTIC_CATEGORIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_categories) structure which indicates which one of the diagnostic categories the diagnostic types being requested belong to.

### `RequestedDiagnostics` [out]

A [DXGK_DIAGNOSTIC_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_types) structure indicates which diagnostic types the driver is being requested to enable in the given category. The driver should enable each diagnostic which is requested and disable each diagnostic which is not requested.