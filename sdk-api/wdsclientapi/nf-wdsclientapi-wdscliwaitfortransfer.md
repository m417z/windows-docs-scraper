# WdsCliWaitForTransfer function

## Description

Waits for an image or file transfer to complete.

## Parameters

### `hTransfer` [in]

A WDS transfer handle for the transfer being canceled. This can be the handle returned by the [WdsCliTransferImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferimage) or [WdsCliTransferFile](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferfile) functions.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

Calling this function from a callback function is not recommended.