# _CMP_SET_PLUG structure

## Description

This structure is used to assign settings to a plug.he request changes transmission settings for a plug control register. Only a driver that created a plug is allowed to set the contents of that plug.

## Members

### `hPlug`

On input, a handle to the plug.

### `Pcr`

On input, an [AV_PCR](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_pcr) structure that contains settings for the plug.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

If a driver attempts to set the contents of a plug register it did not create, the protocol driver sets **Irp->IoStatus.Status** to STATUS_ACCESS_DENIED.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)