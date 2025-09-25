## Description

The **KsCompleteIoOperation** method cleans up the extended header and completes the input and output (I/O) operation.

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

### `Cancelled` [in]

Boolean value that is **TRUE** if the I/O operation was canceled and **FALSE** otherwise.

## Return value

Returns NOERROR if successful; otherwise, returns an error code. If the stream's major type is KSDATAFORMAT_TYPE_AUDIO, a **KsCompleteIoOperation** call is inapplicable, so **KsCompleteIoOperation** automatically returns NOERROR.

## Remarks

The client only calls **KsCompleteIoOperation** if the data type handler indicated to the client the existence of extended header information in a call to the [IKsDataTypeHandler::KsQueryExtendedSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksqueryextendedsize) method.

For more information about **IMediaSample**, see the Microsoft Windows SDK documentation.

## See also

[IKsDataTypeHandler::KsQueryExtendedSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksqueryextendedsize)