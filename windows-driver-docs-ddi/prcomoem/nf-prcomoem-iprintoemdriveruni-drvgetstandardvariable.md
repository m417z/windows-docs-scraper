# IPrintOemDriverUni::DrvGetStandardVariable

## Description

The `IPrintOemDriverUni::DrvGetStandardVariable` method is provided by the Unidrv driver so that rendering plug-ins can obtain the current value of Unidrv's [standard variables](https://learn.microsoft.com/windows-hardware/drivers/print/standard-variables).

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwIndex`

Caller-supplied, SVI_-prefixed index into the list of Unidrv's standard variables. The SVI_-prefixed index values are defined in printoem.h.

### `pBuffer`

Caller-supplied pointer to a DWORD to receive the standard variable's current value.

### `cbSize`

Caller-supplied size of the buffer pointed to by *pBuffer*.

### `pcbNeeded`

Caller-supplied pointer to a location to receive the minimum buffer size required to contain the requested information.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |