# SerCxGetRingBufferUtilization function

## Description

The **SerCxGetRingBufferUtilization** method enables the serial controller driver to determine how much of the type-ahead ring buffer is currently filled by data received from the serial port.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `BytesUsed` [out, optional]

The number of bytes of unread data that are currently contained in the type-ahead ring buffer that is used to store received data.

### `BufferSize` [out, optional]

The size, in bytes, of the type-ahead ring buffer that is used to store received data.

## Remarks

The serial controller driver calls this function to determine how much storage space is available in the type-ahead ring buffer. The serial controller extension (SerCx) maintains this buffer to contain data that the serial controller driver receives from the serial port when no read request from the client is currently being processed. This function provides the information that the driver requires to accurately perform software flow control (XON/XOFF).

To implement software flow control, the serial controller driver monitors the amount of space available in the type-ahead ring buffer. The available space, in bytes, is equal to *BufferSize* - *BytesUsed*. When the available space falls below a client-specified threshold, **XoffLimit**, the serial controller driver transmits an XOFF character to tell the transmitting port to pause transmission. Later, when the available space rises above a client-specified threshold, **XonLimit**, the driver transmits an XON character to tell the transmitting port to resume transmission. Typically, the client specified these two thresholds in a previous [IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow) I/O control request.

SerCx evaluates the available space in the type-ahead ring buffer in the context of the current flow control and handshaking settings. After the type-ahead ring buffer empties completely, SerCx calls the driver's [EvtSerCxReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_receive) callback function so that the driver can send an XON and resume receiving data. The *EvtSerCxReceive* function can call **SerCxGetRingBufferUtilization** to determine whether to send an XON.

## See also

[EvtSerCxReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_receive)

[IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow)