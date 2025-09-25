## Description

The **KSSTREAM_SEGMENT** structure contains information that describes an I/O operation occurring on a stream.

## Members

### `KsInterfaceHandler`

Pointer to a [IKsInterfaceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksinterfacehandler) interface for the I/O operation.

### `KsDataTypeHandler`

Pointer to a [IKsDataTypeHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksdatatypehandler) interface for the I/O operation.

### `IoOperation`

Value that specifies the type of I/O operation. This value can be one of the following values from the KSIOOPERATION enumerated type:

| Value | Description |
|---|---|
| **KsIoOperation_Write** | Write data to stream. |
| **KsIoOperation_Read** | Read data from stream. |

### `CompletionEvent`

Handle to an event that is used to signal that the I/O operation completed.

## See also

[IKsDataTypeHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksdatatypehandler)

[IKsInterfaceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksinterfacehandler)

[IKsInterfaceHandler::KsCompleteIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kscompleteio)

[IKsInterfaceHandler::KsProcessMediaSamples](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-ksprocessmediasamples)

[IKsPin::KsMediaSamplesCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspin-ksmediasamplescompleted)