## Description

The **KsPrepareIoOperation** method initializes the extended header and prepares the media sample for an I/O operation.

## Parameters

### `Sample` [in, out]

Pointer to the **IMediaSample** interface for the associated media sample.

### `StreamHeader` [in, out]

Pointer to a buffer that contains the extended header information.

### `IoOperation` [in]

Value that specifies the type of I/O operation. This value can be one of the following values from the KSIOOPERATION enumerated type:

| Value | Description |
|---|---|
| **KsIoOperation_Write** | Write data to stream. |
| **KsIoOperation_Read** | Read data from stream. |

## Return value

Returns NOERROR if successful; otherwise, returns an error code. If the stream's major type is KSDATAFORMAT_TYPE_AUDIO, a **KsPrepareIoOperation** call is inapplicable, so **KsPrepareIoOperation** automatically returns NOERROR.

## Remarks

The client only calls **KsPrepareIoOperation** if the data type handler indicated to the client the existence of extended header information in a call to the [IKsDataTypeHandler::KsQueryExtendedSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksqueryextendedsize) method.

For more information about **IMediaSample**, see the Microsoft Windows SDK documentation.

## See also

[IKsDataTypeHandler::KsQueryExtendedSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksqueryextendedsize)