# _CMP_CONNECT_VER2 structure

## Description

This structure contains information for a connection request. The request attempts to make a connection to a plug control register on the local host.

## Members

### `hOutputPlug`

On input, a handle to the output plug to use for the connection. If **hOutputPlug** is **NULL**, the connection is for input only.

### `hInputPlug`

On input, handle to the input plug to use for the connection. If **hInputPlug** is **NULL**, the connection is for output only.

### `Type`

On input, the type of the requested connection.

The type of connection to make. Can be one of the following:

#### CMP_Broadcast

A broadcast connection.

#### CMP_PointToPoint

A connection between a single output plug and one or more input plugs.

### `Format`

The requested data format.

On input, a pointer to a [CIP_DATA_FORMAT_VER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_data_format_ver2) structure that specifies the format of the connection.

### `hConnect`

On output, the handle for the created connection.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

If the protocol driver is unable to allocate resources, it sets **Irp->IoStatus.Status** to STATUS_INSUFFICIENT_RESOURCES.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)