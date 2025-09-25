# SERCX_BUFFER_DESCRIPTOR structure

## Description

The **SERCX_BUFFER_DESCRIPTOR** structure describes a data buffer for a receive operation or transmit operation.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCxRetrieveReceiveBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievereceivebuffer) and [SerCxRetrieveTransmitBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievetransmitbuffer) methods use this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `Buffer`

The virtual memory address of the buffer. The memory for the buffer is nonpaged.

### `Length`

The number of bytes available in the buffer. This size determines the maximize number of bytes that can be transferred by the receive or transmit operation.

## Remarks

The serial controller driver uses the information in this structure to determine where in memory to read data from during a receive operation, and where in memory to write data during a transmit operation.

At any time, there can be no more than one valid receive buffer and one valid transmit buffer. The controller driver calls the [SerCxRetrieveReceiveBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievereceivebuffer) method to obtain the receive buffer, and calls the [SerCxRetrieveTransmitBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievetransmitbuffer) method to obtain the transmit buffer. Both methods copy buffer descriptions into caller-allocated **SERCX_BUFFER_DESCRIPTOR** structures. A subsequent call to one of these methods invalidates the previously issued descriptor for the receive buffer or transmit buffer, respectively. The caller must not access a buffer that is described by a buffer descriptor that is no longer valid.

The buffers that are obtained by successive calls to **SerCxRetrieveReceiveBuffer** or **SerCxRetrieveTransmitBuffer** are not guaranteed to be contiguous.

The controller driver must call the [SERCX_BUFFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_buffer_descriptor_init) function to initialize an **SERCX_BUFFER_DESCRIPTOR** structure before the structure is passed to the [SerCxRetrieveReceiveBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievereceivebuffer) or [SerCxRetrieveTransmitBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievetransmitbuffer) method. After a buffer descriptor is initialized, it can be reused without being initialized again.

## See also

[SERCX_BUFFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_buffer_descriptor_init)

[SerCxRetrieveReceiveBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievereceivebuffer)

[SerCxRetrieveTransmitBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievetransmitbuffer)