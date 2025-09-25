# SerCxRetrieveReceiveMdl function

## Description

The **SerCxRetrieveReceiveMdl** method retrieves the MDL that describes the buffer to use to receive the next block of input data.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Mdl` [out]

A pointer to a location into which the method writes a pointer to the MDL.

## Return value

**SerCxRetrieveReceiveMdl** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | This value is returned if one of the following occurs:<br><br>* There is no outstanding receive request to get an MDL from.<br>* The current number of bytes received (as reported by the [SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive) method) does not equal zero.<br>* The buffer has already been retrieved (and the corresponding call to the **SerCxProgressReceive** method has not yet occurred).<br>* The MDL has already been retrieved (and the corresponding call to the **SerCxProgressReceive** method has not yet occurred). |

## Remarks

The serial controller driver calls this function to obtain an MDL to use for the current receive (read) operation. The MDL describes the buffer memory into which the driver is to transfer the received data. The driver is the exclusive owner of this MDL until it calls the [SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive) method, after which the MDL pointer is invalid and the driver must no longer try to access either the MDL or the buffer memory that the MDL describes.

For more information about MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive)