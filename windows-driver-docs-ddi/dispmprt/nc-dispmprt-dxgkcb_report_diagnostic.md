# DXGKCB_REPORT_DIAGNOSTIC callback function

## Description

Implemented by the kernel mode driver to report diagnostic logging.

## Parameters

### `DeviceHandle`

A handle to a display device adapter.

### `pDiagnostic`

Pointer to a [DXGK_DIAGNOSTIC_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_header) structure that contains the diagnostic event report.

## Return value

Returns the following values:

| Value | Description |
| -- | -- |
| STATUS_SUCCESS| The diagnostic event is recorded successfully by the OS.|
| STATUS_INVALID_PARAMETER| The adapter handle is incorrect or the event type is not recognized. |
| STATUS_BUFFER_TOO_SMALL | the event size is too small for the type. |
| STATUS_UNSUCCESSFUL | The OS was unable to process a valid event.|

Other return codes may be returned as appropriate.

## Prototype

```cpp
//Declaration

DXGKCB_REPORT_DIAGNOSTIC DxgkcbReportDiagnostic;

// Definition

_IRQL_requires_same_ DxgkcbReportDiagnostic
(
    HANDLE DeviceHandle
    IN_PDXGK_DIAGNOSTIC_HEADER pDiagnostic
)
{...}

DXGKCB_REPORT_DIAGNOSTIC

```