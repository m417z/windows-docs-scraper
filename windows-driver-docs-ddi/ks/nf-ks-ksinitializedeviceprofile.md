# KsInitializeDeviceProfile function

## Description

The **KsInitializeDeviceProfile** API must be called by all miniport drivers to initialize the profile store and publish the device profiles.

## Parameters

### `FilterFactory` [in]

This is the [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) that was created by the camera driver to uniquely identify the camera’s filter factory.

## Return value

If the provided **KSFILTERFACTORY** does not contain a device interface associated with the **KSCATEGORY_VIDEO_CAMERA**, this API call will fail with **STATUS_INVALID_PARAMETER**.

## Remarks

It is required that the **ReferenceGuid** field of the [KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) structure contained with the **KSFILTERFACTORY** be set with a unique GUID for this filter type. And the **Flags** field of the **KSFILTER_DESCRIPTOR** has the **KSFILTER_FLAG_PRIORITIZE_REFERENCEGUID** flag set.

To delete all profiles from the profile store associated with the device interface for this **KSFILTERFACTORY**, the driver may call **KsInitializeDeviceProfile** followed immediately by [KsPersistDeviceProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspersistdeviceprofile). This would result in an empty profile information, which would remove the profile information from the profile store.