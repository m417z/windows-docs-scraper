# _CMP_DELETE_PLUG structure

## Description

This structure is used to delete a plug.The request deletes a plug control register (iPCR or oPCR) that was created with Av61883_CreatePlug. A driver is responsible for deleting all of the plugs it has created before the system unloads the driver.

## Members

### `hPlug`

On input, a handle to the plug to delete.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)