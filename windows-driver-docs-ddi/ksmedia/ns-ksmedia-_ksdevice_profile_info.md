# _KSDEVICE_PROFILE_INFO structure

## Description

The **KSDEVICE_PROFILE_INFO** is a generic structure designed to handle profile information for various device types.

## Members

### `Type`

Defines the type of profile. Currently, the only defined type is **KSDEVICE_PROFILE_TYPE_CAMERA**.

```cpp
#define KSDEVICE_PROFILE_TYPE_CAMERA    0x00000001
```

### `Size`

This must be set to sizeof(KSDEVICE_PROFILE_INFO) structure.

### `Camera`

### `Camera.Info`

Structure of [KSCAMERA_PROFILE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_kscamera_profile_info) defining the profile information of a camera.

### `Camera.Reserved`

Unused. Must be set to 0.

### `Camera.ConcurrencyCount`

Number of [KSCAMERA_PROFILE_CONCURRENCYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_kscamera_profile_concurrencyinfo) structures in the **Concurrency** array.

For Windows 10 this must be less than or equal 1.

A value of 0 with **Concurrency** set to **NULL**, indicates this profile is non-concurrent.

### `Camera.Concurrency`

An array of **KSCAMERA_PROFILE_CONCURRENCYINFO** structures describing the concurrency support for this profile.

If **CountOfConcurrency** is 0, this parameter must be **NULL**.

If **CountOfConcurrency** is greater than 0, this parameter must not be **NULL**.