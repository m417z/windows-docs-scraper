# DDGETTRANSFERSTATUSOUTINFO structure

## Description

The DDGETTRANSFERSTATUSOUTINFO structure contains the transfer status information.

## Members

### `dwTransferID`

Contains the transfer ID of the bus master transfer that completed. The transfer ID was originally supplied to the driver in the **dwTransferID** member of the [DDTRANSFERININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferininfo) structure. The driver receives a pointer to DDTRANSFERININFO in a call to its [DxTransfer](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_transfer) function.

## See also

[DDTRANSFERININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddtransferininfo)

[DxGetTransferStatus](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_gettransferstatus)

[DxTransfer](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_transfer)