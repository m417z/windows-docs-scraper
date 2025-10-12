# KsCreateFilterFactory function

## Description

The **KsCreateFilterFactory** function adds a filter factory to a given device.

## Parameters

### `DeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure for which to add a filter factory.

### `Descriptor` [in]

A pointer to a [KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) that describes the characteristics of individual filters that this factory can create.

### `RefString` [in, optional]

If this argument is provided, this string is used as the reference string for filters created by this factory. Otherwise, the reference GUID provided in the descriptor is used.

### `SecurityDescriptor` [in, optional]

The security descriptor to use in creation of filters by this filter factory. If **NULL**, no descriptor is provided.

### `CreateItemFlags` [in]

The following table lists the flags that the minidriver writer uses to specify the characteristics of filters that the new filter factory can create. Set this parameter to the bitwise OR of the flags below.

| Flag | Meaning |
| --- | --- |
| KSCREATE_ITEM_SECURITY_CHANGED | Indicates that the security descriptor on this object type has been changed and should be persisted. |
| KSCREATE_ITEM_WILDCARD | Indicates that this create item represents a wildcard that is used for any create requests that do not match any other create items. The ordering of the wildcard entry in the list of create items is irrelevant. Only a single wildcard entry is valid on any list of create items. |
| KSCREATE_ITEM_NOPARAMETERS | Indicates that this create item does not allow any parameters to be passed, and fails if any are found. (Normally, create parameters are passed on to the create handler.) This flag cannot be used with a wildcard flag. |
| KSCREATE_ITEM_FREEONSTOP | Indicates that the create item should be freed when the PnP manager sends [IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device). Note that AVStream automatically frees such create items when the device receives PnP stop (*after* the client has received the PnP stop notification). |

### `SleepCallback` [in, optional]

A pointer to a minidriver-provided routine that receives notifications that the device associated with this filter is going to sleep. Prototype the routine as follows:

```cpp
void SleepCallback (IN PKSFILTERFACTORY FilterFactory,
    IN DEVICE_POWER_STATE State);
```

If this parameter is **NULL**, this filter factory is not notified that the device is going to sleep. See [Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states).

### `WakeCallback` [in, optional]

A pointer to a minidriver-provided routine that receives notifications that the device associated with this filter is waking up. Prototype the routine as follows:

```cpp
void WakeCallback (IN PKSFILTERFACTORY FilterFactory,
    IN DEVICE_POWER_STATE State);
```

If this parameter is **NULL**, this filter factory is not notified that the device is waking up. See [Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states).

### `FilterFactory` [out, optional]

A pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure that AVStream sets to point to the newly created filter factory object. If this optional parameter is unspecified, the caller is not informed about the resulting filter factory object.

## Return value

Returns STATUS_SUCCESS if the filter factory can be created. Otherwise, it returns an appropriate error code.

## Remarks

If you call **KsCreateFilterFactory** after [AVStrMiniDevicePostStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevice)), you must then call [KsFilterFactorySetDeviceClassesState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorysetdeviceclassesstate) to enable the device class. (Also call **KsFilterFactorySetDeviceClassesState** to disable a filter factory.)

If you call **KsCreateFilterFactory** in the context of *AVStrMiniDevicePostStart* or before, you do not need to do this.

Before calling this function, the minidriver must obtain the device mutex. For information about how to do this, see [Device Mutex in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/device-mutex-in-avstream).

This function should be used by minidrivers that either initialize themselves without a call to [KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver) or that must dynamically add and remove new filter types.

## See also

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KSNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KsDeleteFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeletefilterfactory)