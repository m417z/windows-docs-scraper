# SerCxProgressReceive function

## Description

The **SerCxProgressReceive** method reports the progress of the current read (receive) operation.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `BytesReceived` [in]

The number of bytes of data that the caller loaded into the receive buffer that was obtained by the latest call to the [SerCxRetrieveReceiveBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievereceivebuffer) method.

### `ReceiveStatus` [in]

The current status of the receive operation. Set this parameter to one of the following values:

* **SerCxStatusSuccess**
* **SerCxStatusCancelled**
* **SerCxStatusTimeout**

For more information about these values, see [SERCX_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx_status).

## Return value

**SerCxProgressReceive** returns STATUS_SUCCESS if it is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *BytesReceived* value exceeds the available buffer length; or the *ReceiveStatus* value is not valid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The method was called at the wrong IRQL; or the WDFDEVICE handle is not valid; or the driver has not obtained an input buffer for this receive operation. |
| **STATUS_CANCELLED** | The receive operation has already been canceled. |

## Remarks

The serial controller driver calls this method to report progress on an outstanding read operation. Typically, the serial controller driver calls this method from its DMA completion callback (if the driver uses DMA to read the data) or from its transmit/receive DPC function (if PIO is used).

If the **SerCxProgressReceive** does not complete all outstanding work for the read operation, the caller must call the [SerCxRetrieveReceiveBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievereceivebuffer) method again to get a new buffer descriptor and continue to receive data.

## See also

[SERCX_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx_status)

[SerCxRetrieveReceiveBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxretrievereceivebuffer)