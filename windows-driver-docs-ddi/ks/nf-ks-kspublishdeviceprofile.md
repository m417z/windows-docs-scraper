# KsPublishDeviceProfile function

## Description

The **KsPublishDeviceProfile** API is called to publish device profile information.

## Parameters

### `FilterFactory` [in]

This is the same [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) used in the [KsInitializeDeviceProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedeviceprofile) API.

### `Profile` [in]

This is a camera profile of type [KSDEVICE_PROFILE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ksdevice_profile_info).

## Return value

Camera profile information will only be associated with the **KSCATEGORY_VIDEO_CAMERA** interface category. Any filter factory created without this interface category and attempting to register a camera profile will result in this API returning a **STATUS_INVALID_PARAMETER**.

## Remarks

This API will be called repeatedly for each profile the camera driver supports. Each call may have different set of concurrency and data range information. The **ProfileId** field of the **KSCAMERA_PROFILE_INFO** must be unique. If the same **ProfileId** is used and the content of the profile information is different, the subsequent call will overwrite the earlier profile information.