## Description

The *DxGetTransferStatus* callback function is used by DirectDraw to determine which hardware bus master has completed.

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Reserved for system use.

### `unnamedParam3`
Points to a [DDGETTRANSFERSTATUSOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgettransferstatusoutinfo) structure that contains the transfer status information.

## Return value

*DxGetTransferStatus* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The driver identifies the bus master by supplying the transfer ID in the DDGETTRANSFERSTATUSOUTINFO structure. The transfer ID for each bus master is originally supplied by DirectDraw in the **dwTransferID** member of the [DDTRANSFERININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferininfo) structure. DirectDraw passes a pointer to DDTRANSFERININFO in its call to the driver's [DxTransfer](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_transfer) function.

## See also

[DDGETTRANSFERSTATUSOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgettransferstatusoutinfo)

[DDTRANSFERININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferininfo)

[DxTransfer](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_transfer)