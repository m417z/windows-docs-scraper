# _CMP_GET_PLUG_HANDLE structure

## Description

This structure is used in getting the handle of a plug. The request retrieves a unique handle associated with an input or output plug. The plug handle is required for all operations on the plug. A driver uses a plug handle to get the state of a plug, modify plug settings, or delete a plug. A driver can delete only plugs it has previously created.

## Members

### `PlugNum`

The number of the plug whose handle was returned by the Av61883_CreatePlug request that created the plug.

### `Type`

The type of the plug. This can be CMP_PlugOut for an output plug, or CMP_PlugIn for an input plug.

### `hPlug`

On output, a handle to the plug specified with PlugNum and Type.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)