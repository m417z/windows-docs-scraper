# ChangerInitialize function

## Description

**ChangerInitialize** readies the changer to receive other requests.

## Parameters

### `DeviceObject` [in]

Pointer to the device object created by the changer class driver to represent this changer.

## Return value

**ChangerInitialize** returns the STATUS_*XXX* value returned by the system port driver or one of the following values:

STATUS_SUCCESS

STATUS_INSUFFICIENT_RESOURCES

## Remarks

The changer class driver calls **ChangerInitialize** during driver initialization, after creating a device object to represent a changer.

**ChangerInitialize** performs any device-specific processing required to get the changer ready to receive requests. It also typically stores device-specific information in the device extension, such as SCSI inquiry data or the non-SCSI equivalent and offsets to generate zero-based element addresses, which are used by the system to refer to changer elements.

After **ChangerInitialize** returns, the changer miniclass driver and the changer should be able to handle any other request.

## See also

[ChangerAdditionalExtensionSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changeradditionalextensionsize)