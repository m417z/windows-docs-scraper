# DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT callback function

## Description

The OS calls the DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT callback function to discover what types of diagnostic the driver supports for the passed diagnostic category.

## Parameters

### `MiniportDeviceContext`

A handle to a context block associated with a display adapter.

### `pArgQueryDiagnosticTypesSupport`

Pointer to a [DXGKARG_QUERYDIAGNOSTICTYPESSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_querydiagnostictypessupport) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT DxgkddiQuerydiagnostictypessupport;

// Definition

NTSTATUS DxgkddiQuerydiagnostictypessupport
(
	IN_CONST_PVOID MiniportDeviceContext
	INOUT_PDXGKARG_QUERYDIAGNOSTICTYPESSUPPORT pArgQueryDiagnosticTypesSupport
)
{...}

DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT *PDXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT

```

## Remarks

## See also