# IPrintCoreUI2::QuerySimulationSupport

## Description

The `IPrintCoreUI2::QuerySimulationSupport` method retrieves a spooler simulation capability structure, which indicates the kinds of simulation the spooler supports.

## Parameters

### `hPrinter` [in]

Specifies a handle to the printer.

### `dwLevel` [in]

Specifies the spooler simulation capability structure returned in the buffer pointed to by *pCaps*. Currently, only level 1 of spooler simulation support is provided.

| Value | Spooler Simulation Support Structure |
| --- | --- |
| 1 | [SIMULATE_CAPS_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_simulate_caps_1) (defined in printoem.h) |

### `pCaps` [out]

Pointer to the output buffer, which contains a structure of the type indicated by the value in the *dwLevel* parameter.

### `cbSize` [in]

Specifies the size, in bytes, of the output buffer, which is pointed to by *pCaps*.

### `pcbNeeded` [out]

Specifies the size, in bytes, of the memory needed to store a structure of the type indicated by *dwLevel*.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pCaps*).<br><br>The method was called with *pCaps* set to **NULL**. |
| **E_NOTIMPL** | The method is not supported.<br><br>A structure of the type specified by *dwLevel* is not supported. |
| **E_FAIL** | The method failed |

## Remarks

This method is supported only for Windows XP Pscript5 plug-ins, not for Unidrv plug-ins.

The `IPrintCoreUI2::QuerySimulationSupport` method stores a spooler simulation capability structure in the buffer pointed to by *pCaps*. This structure specifies the level of spooler support for "N-up" printing, reverse printing, the maximum number of pages that can be printed, collation, and others.

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[SIMULATE_CAPS_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_simulate_caps_1)