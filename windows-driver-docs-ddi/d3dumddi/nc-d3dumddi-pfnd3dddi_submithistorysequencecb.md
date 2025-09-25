## Description

**PFND3DDDI_SUBMITHISTORYSEQUENCECB** associates history buffer data with a particular hardware queue and progress fence ID.

## Parameters

### `hDevice`

[in] A handle to the device.

### `unnamedParam2`

[in] Pointer to a [**D3DDDICB_SUBMITHISTORYSEQUENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_submithistorysequence) structure that contains the arguments for this callback function.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also

[**D3DDDICB_SUBMITHISTORYSEQUENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_submithistorysequence)