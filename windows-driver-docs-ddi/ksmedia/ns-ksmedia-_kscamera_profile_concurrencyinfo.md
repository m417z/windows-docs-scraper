# _KSCAMERA_PROFILE_CONCURRENCYINFO structure

## Description

An array of **KSCAMERA_PROFILE_CONCURRENCYINFO** structures form the **Camera.Concurrency** parameter of the [KSDEVICE_PROFILE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ksdevice_profile_info) structure (whose array size is specified by **Camera.CountOfConcurrency** parameter) indicating which profiles the profile identified in the [KSCAMERA_PROFILE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_kscamera_profile_info) structure may run simultaneously on different cameras.

## Members

### `ReferenceGuid`

Must be set to the **ReferenceGuid** of the **KSFILTER_DESCRIPTOR** which corresponds to the other device with which this profile is concurrent.

### `Reserved`

Unused. Must be 0.

### `ProfileCount`

Number of profile IDs contained in the **Profiles** array. Must be greater than 0.

### `Profiles`

This is an array of **KSCAMERA_PROFILE_INFO** structures that can be simultaneously used on the other camera device specified by the **ReferenceGuid**. This field must not be **NULL**.

## Remarks

Currently, an application has no knowledge as to whether it can attempt to stream from more than one camera until the attempt succeeds or fails. In the case of web blogging scenario, this means the application will have to attempt to activate both streams before it paints the UI with a picture in picture video element.

For multiple applications, concurrency will not be sufficient to guarantee concurrent operation. The concurrency information will not attempt to solve this scenario. Instead, the existing camera yanking feature will be leveraged.

If both **Camera.CountOfConcurrency** and the **Camera.Concurrency** fields are 0 and **NULL** respectively, it indicates to the OS that the profile defined by the KSCAMERA_PROFILE_INFO is not a concurrent profile.