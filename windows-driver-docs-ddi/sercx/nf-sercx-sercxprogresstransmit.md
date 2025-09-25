# SerCxProgressTransmit function

## Description

The **SerCxProgressTransmit** method reports the progress of the current write (transmit) operation.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `BytesTransmitted` [in]

The number of bytes of data that the caller copied from the transmit buffer that was obtained by the latest call to the [SerCxRetrieveTransmitBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievetransmitbuffer) method.

### `TransmitStatus` [in]

The current status of the transmit operation. Set this parameter to one of the following values:

* **SerCxStatusSuccess**
* **SerCxStatusCancelled**

For more information about these values, see [SERCX_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx_status).

**Note** The **SerCxStatusTimeout** value is valid only for receive operations. No interval time-out can be specified for a transmit operation. For more information, see [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts).

## Return value

**SerCxProgressTransmit** returns STATUS_SUCCESS if it is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *BytesTransmitted* value exceeds the available buffer length; or the *TransmitStatus* value is not valid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The method was called at the wrong IRQL; or the WDFDEVICE handle is not valid; or the driver has not obtained an output buffer for this transmit operation. |
| **STATUS_CANCELLED** | The transmit operation has already been canceled. |

## Remarks

The serial controller driver calls this method to report progress on an outstanding write operation. Typically, the serial controller driver calls this method from its DMA completion callback (if the driver uses DMA to read the data) or from its transmit/receive DPC function (if PIO is used).

If the **SerCxProgressTransmit** call does not complete all outstanding work for the write operation, the caller must call [SerCxRetrieveTransmitBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievetransmitbuffer) again to get a new buffer descriptor and continue to transmit data.

## See also

[SERCX_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx_status)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCxRetrieveTransmitBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievetransmitbuffer)