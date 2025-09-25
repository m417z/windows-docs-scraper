# DlEvalAcpiMethod function

## Description

Evaluates a specified ACPI method on a display adapter or on a child device of a display adapter.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `DeviceUid`

The unique identifier for the ACPI device on which the method will be evaluated.

### `AcpiInputBuffer`

The ACPI input buffer.

### `AcpiInputSize`

The ACPI input size.

### `AcpiOutputBuffer`

The ACPI output buffer.

### `AcpiOutputSize`

The ACPI output size.

## Return value

This function returns NTSTATUS.

## Remarks

## See also

[DXGKCB_EVAL_ACPI_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_eval_acpi_method) callback function