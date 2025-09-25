# WdsCliGetImageHandleFromTransferHandle function

## Description

Returns an image handle from a completed transfer handle. The handle is to the local copy of the image that's been transferred from the server to the client.

## Parameters

### `hTransfer`

A WDS transfer handle that has completed the transfer. This can be the handle returned by the [WdsCliTransferImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferimage) or [WdsCliTransferFile](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferfile) functions.

### `phImageHandle` [out]

A pointer to a location that contains an image handle.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

If the transfer is not yet complete when this function is called, it will return an error code.

Use the [WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose) function to close the image handle returned by this function.