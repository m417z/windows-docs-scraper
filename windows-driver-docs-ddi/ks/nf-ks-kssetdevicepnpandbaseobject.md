## Description

The **KsSetDevicePnpAndBaseObject** function sets the PnP device object in the device header, which is the next device object on the PnP stack and is the device object that PnP requests are forwarded to if **KsDefaultDispatchPnp** is used.

## Parameters

### `Header` [in]

Points to a header previously allocated by **KsAllocateDeviceHeader** in which to put the PnP device object.

### `PnpDeviceObject` [in]

Specifies the PnP device object to place in the device header, overwriting any previously set device object.

### `BaseObject`

Specifies the base device object to which this device header is attached. This must be set if **KsRecalculateStackDepth** is used.

## Return value

None

## See also

[KsAllocateDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedeviceheader)

[KsRecalculateStackDepth](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksrecalculatestackdepth)