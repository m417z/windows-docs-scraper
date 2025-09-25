# SerCxRetrieveTransmitMdl function

## Description

The **SerCxRetrieveTransmitMdl** method retrieves the MDL that describes the buffer that contains the next block of output data to be transmitted.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Mdl` [out]

A pointer to a location into which the method writes a pointer to the MDL.

## Return value

**SerCxRetrieveTransmitMdl** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | This value is returned if one of the following occurs:<br><br>* There is no outstanding transmit request to get an MDL from.<br>* The current number of bytes transmitted (as reported by the [SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit) method) does not equal zero.<br>* The buffer has already been retrieved (and the corresponding call to the **SerCxProgressTransmit** method has not yet occurred).<br>* The MDL has already been retrieved (and the corresponding call to the **SerCxProgressTransmit** method has not yet occurred). |

## Remarks

The serial controller driver calls this function to obtain an MDL to use for the current transmit (write) operation. The MDL describes the buffer memory from which the driver is to obtain the data to be transmitted. The driver is the exclusive owner of this MDL until it calls the [SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit) method, after which the MDL pointer is invalid and the driver must no longer try to access either the MDL or the buffer memory that the MDL describes.

For more information about MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit)