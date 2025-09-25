# IPrintOemDriverUni::DrvGetGPDData

## Description

The `IPrintOemDriverUni::DrvGetGPDData` method is provided by the Unidrv driver so that rendering plug-ins can obtain data defined in a printer's [GPD](https://learn.microsoft.com/windows-hardware/drivers/) file.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwType`

Caller-supplied flag indicating the type of GPD data being requested. Currently, the following flag is the only one defined:

| Flag | Definition |
| --- | --- |
| GPD_OEMCUSTOMDATA | The method returns the string associated with a GPD file's ***OEMCustomData** entry. |

### `pInputData`

Reserved. Must be zero.

### `pBuffer`

Caller-supplied pointer to a buffer to receive the requested information.

### `cbSize`

Caller-supplied size, in bytes, of the buffer pointed to by *pBuffer*.

### `pcbNeeded`

Receives the driver-supplied minimum buffer size, in bytes, required to contain the requested information.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

If the buffer specified by *pBuffer* and *cbSize* is too small to receive the requested information, Unidrv supplies the required buffer size in the location pointed to by *pcbNeeded*, returns E_FAIL, and sets the error code to ERROR_INSUFFICIENT_BUFFER.