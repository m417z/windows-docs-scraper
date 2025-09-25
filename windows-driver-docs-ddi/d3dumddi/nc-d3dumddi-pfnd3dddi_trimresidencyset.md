# PFND3DDDI_TRIMRESIDENCYSET callback function

## Description

**pfnTrimResidencySet** is used to trim the residency list for a given device. User mode drivers are required to implement this callback in order to participate in the new memory residency model.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_TRIMRESIDENCYSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_trimresidencyset) structure that provides the details of the requested operation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[D3DDDIARG_TRIMRESIDENCYSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_trimresidencyset)