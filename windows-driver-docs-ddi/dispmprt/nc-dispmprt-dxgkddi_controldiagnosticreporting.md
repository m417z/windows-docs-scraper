# DXGKDDI_CONTROLDIAGNOSTICREPORTING callback function

## Description

The OS calls DxgkddiControlDiagnosticReporting to apply the set of diagnostics which should be enabled for a diagnostic category. Any diagnostics which are not included in the set should be disabled.

## Parameters

### `MiniportDeviceContext`

Identifies the adapter.

### `pArgControlDiagnosticReporting`

A pointer to a [DXGKARG_QUERYDIAGNOSTICTYPESSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_querydiagnostictypessupport) structure that indicates the category of diagnostic being queried and provides space for the driver to describe the diagnostic support it has.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS Values error code defined in Ntstatus.h.

## Prototype

```cpp
//Declaration

DXGKDDI_CONTROLDIAGNOSTICREPORTING DxgkddiControldiagnosticreporting;

// Definition

NTSTATUS DxgkddiControldiagnosticreporting
(
	IN_CONST_PVOID MiniportDeviceContext
	IN_PDXGKARG_CONTROLDIAGNOSTICREPORTING pArgControlDiagnosticReporting
)
{...}

DXGKDDI_CONTROLDIAGNOSTICREPORTING *PDXGKDDI_CONTROLDIAGNOSTICREPORTING

```

## Remarks

This function is always called at PASSIVE level so the supporting code should be made pageable.

## See also

[DXGKARG_QUERYDIAGNOSTICTYPESSUPPORT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_querydiagnostictypessupport)