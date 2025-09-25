# WdsCliCancelTransfer function

## Description

Cancels a WDS transfer operation.

## Parameters

### `hTransfer` [in]

A handle for the WDS transfer operation being canceled. This can be the handle returned by the [WdsCliTransferImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferimage) or [WdsCliTransferFile](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferfile) functions.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This function can be called from a callback function.