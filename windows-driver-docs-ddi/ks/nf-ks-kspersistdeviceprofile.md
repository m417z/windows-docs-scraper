# KsPersistDeviceProfile function

## Description

The **KsPersistDeviceProfile** API commits the profile information to the persistent store.

## Parameters

### `FilterFactory` [in]

This is the [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) that was used to initialize the profile store in [KsInitializeDeviceProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedeviceprofile).

## Return value

If **KsPersistDeviceProfile** is called without first initializing the profile store with **KsInitializeDeviceProfile** the call to **KsPersistDeviceProfile** will fail with **STATUS_INVALID_DEVICE_REQUEST**.
Furthermore, this API may also fail with **STATUS_INSUFFICIENT_RESOURCE** if the page pool is exhausted when profile information is being persisted.