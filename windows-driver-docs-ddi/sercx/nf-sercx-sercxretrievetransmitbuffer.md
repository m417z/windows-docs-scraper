# SerCxRetrieveTransmitBuffer function

## Description

The **SerCxRetrieveTransmitBuffer** method obtains an output buffer that contains data that is ready to be transmitted to the serial port.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Length` [in]

The requested buffer length, in bytes. If the **SerCxRetrieveTransmitBuffer** call succeeds, the caller receives an output buffer that contains up to *Length* bytes of available data. (The available data in the buffer might be less than *Length* bytes.) **SerCxRetrieveTransmitBuffer** writes the actual number of bytes of available data to the **Length** member of the structure pointed to by the *BufferDescriptor* parameter.

### `BufferDescriptor` [in, out]

A pointer to a caller-allocated [SERCX_BUFFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-sercx_buffer_descriptor) structure. This structure describes the data buffer to use for the transmit operation. The caller previously called the [SERCX_BUFFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_buffer_descriptor_init) function to initialize this structure. **SerCxRetrieveTransmitBuffer** writes to the **Buffer** and **Length** members of this structure.

## Return value

**SerCxRetrieveTransmitBuffer** returns STATUS_SUCCESS if it is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The method was called at the wrong IRQL; or the WDFDEVICE handle is not valid; or either *Device* or *BufferDescriptor* is NULL; or the driver already has a transmit buffer. |
| **STATUS_INFO_LENGTH_MISMATCH** | The wrong size is specified for the **SERCX_BUFFER_DESCRIPTOR** structure. |
| **STATUS_INSUFFICIENT_RESOURCES** | Could not allocate system resources (typically memory). |

## Remarks

The serial controller driver calls this method to acquire a buffer that contains the output data for the current transmit (write) operation.

## See also

[SERCX_BUFFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-sercx_buffer_descriptor)

[SERCX_BUFFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_buffer_descriptor_init)