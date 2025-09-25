## Description

The *DxGetIRQInfo* callback function indicates that the driver manages the interrupt request.

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Reserved for system use.

### `unnamedParam3`
Points to a [DDGETIRQINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetirqinfo) structure that contains the interrupt request information.

## Return value

*DxGetIrqInfo* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

Because the miniport driver must always manage the IRQ, this function must always set the **dwFlags** member of the DDGETIRQINFO structure at *GetIrqInfo* to IRQINFO_HANDLED. If any other flag is set, this function will fail.

## See also

[DDGETIRQINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetirqinfo)