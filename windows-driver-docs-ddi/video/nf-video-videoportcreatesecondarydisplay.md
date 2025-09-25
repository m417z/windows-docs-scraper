# VideoPortCreateSecondaryDisplay function

## Description

The **VideoPortCreateSecondaryDisplay** function enables dual-view support by creating a secondary device object for the given device.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension. This is the hardware extension for the device that wants to create additional display device objects.

### `SecondaryDeviceExtension` [in, out]

Pointer to the location in which to store the hardware device extension for the secondary display device.

### `ulFlag` [in]

Is a set of attributes for the secondary display device. This parameter is restricted to the following value:

|Value|Meaning|
|--- |--- |
|VIDEO_DUALVIEW_REMOVABLE|The secondary view can be removed.|

## Return value

**VideoPortCreateSecondaryDisplay** returns NO_ERROR if the secondary display device was successfully created. Otherwise, this function returns an error code.

## Remarks

In Windows XP and later, a removable logical device will never become the [primary display](https://learn.microsoft.com/windows-hardware/drivers/).

Note that on some editions of Windows XP, **VideoPortCreateSecondaryDisplay** can deliberately fail to enable Dualview. In such cases, the display driver should remain in SingleView mode.

When the video miniport driver calls **VideoPortCreateSecondaryDisplay**, the value of the *ulFlags* parameter must be equal to VIDEO_DUALVIEW_REMOVABLE, which is defined in *ntddvdeo.h*.

The flags VIDEO_DUALVIEW_PRIMARY and VIDEO_DUALVIEW_SECONDARY, which are defined in *ntddvdeo.h*, are for internal use only. The video miniport driver must never set these flags.