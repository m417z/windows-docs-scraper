## Description

The **KsProcessMediaSamples** method processes media samples.

## Parameters

### `KsDataTypeHandler` [in]

Pointer to the [IKsDataTypeHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksdatatypehandler) interface for the data type handler that handles the type of media listed at *SampleList*. This data type handler has specific information about the media type being streamed.

### `SampleList` [in]

Pointer to a buffer that contains an array of pointers to the **IMediaSample** interfaces for the list of media samples to process.

### `SampleCount` [in, out]

Pointer to a variable that initially contains the number of samples in the list at *SampleList* and, on return, receives the actual number of samples processed.

### `IoOperation` [in]

Value that specifies the type of I/O operation. This value can be one of the following values from the KSIOOPERATION enumerated type:

| Value | Description |
|---|---|
| **KsIoOperation_Write** | Write data to stream. |
| **KsIoOperation_Read** | Read data from stream. |

### `StreamSegment` [out]

Pointer to a buffer that receives a pointer to a [KSSTREAM_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/ns-ksproxy-_ksstream_segment) structure that contains header information for a stream segment that is sent to the kernel-mode pin.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsProcessMediaSamples** method moves samples from or to a previously assigned filter pin. A stream header is initialized to represent each media sample in the stream segment. The input and output (I/O) are then performed, the count of wait items is incremented, and the proxy I/O thread waits for completion.

The **KsProcessMediaSamples** method calls the [KsQueryExtendedSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksqueryextendedsize) method of the received [IKsDataTypeHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksdatatypehandler) interface to retrieve the size of the extended header. If an extended header size is not specified, **KsProcessMediaSamples** discards the pointer to the **IKsDataTypeHandler** interface. If an extended header size is specified, **KsProcessMediaSamples** holds the pointer to the **IKsDataTypeHandler** interface until processing of the media samples is complete. The **KsProcessMediaSamples** method then allocates the stream headers with the appropriate header sizes. For each media sample, **KsProcessMediaSamples** initializes the header, copies data pointers, sets time stamps, and so on. Each sample is then added to the sample list. If it is a write operation, the sample is held by incrementing the reference count.

For more information about **IMediaSample**, see the Microsoft Windows SDK documentation.

## See also

[IKsDataTypeHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksdatatypehandler)

[IKsDataTypeHandler::KsQueryExtendedSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksqueryextendedsize)

[KSSTREAM_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/ns-ksproxy-_ksstream_segment)