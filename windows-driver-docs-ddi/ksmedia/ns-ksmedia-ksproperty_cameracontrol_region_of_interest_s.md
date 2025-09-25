## Description

Describes region of interest (ROI) control properties in the **PROPSETID_VIDCAP_CAMERACONTROL_REGION_OF_INTEREST** camera control property set. The region of interest is a rectangle in the image that is used to focus the camera. This structure specifies property values that are used in requests to the camera driver.

## Members

### `FocusRect`

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the rectangular region in which the device should set the focus. This structure is available only to Windows apps.

If **FocusRect** is not a valid value, or if all members of the [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure are zero, the device should focus the center of the image and the remaining members of this structure can be ignored.

The rectangle's coordinates are with respect to the preview video resolution.

### `AutoFocusLock`

If **TRUE**, the device should lock the focus to the current value.

This member should be ignored if **FocusRect** is not a valid value.

### `AutoExposureLock`

If **TRUE**, the device should lock the exposure to the current value.

This member should be ignored if **FocusRect** is not a valid value.

### `AutoWhitebalanceLock`

If **TRUE**, the device should lock the white balance setting to the current value.

This member should be ignored if **FocusRect** is not a valid value.

### `Capabilities`

Indicates whether the device and driver support setting the region of interest automatically or manually. This member a bitwise **OR** of these possible values:

| Value | Meaning |
|---|---|
| KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_FLAGS_AUTO | The device and driver can automatically set the region of interest. |
| KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_FLAGS_MANUAL | The user can manually set the region of interest. |
| KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_FLAGS_ASYNC | ROI control features execute asynchronously. This capability is available starting with Windows 8.1. |

### `Configuration`

Configuration flags for control operations for the region. This is a bitwise OR combination of the following values.

This member is available starting with Windows 8.1.

| Value | Meaning |
| --- | --- |
| KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONFIG_FOCUS | Set auto focus for the region. |
| KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONFIG_EXPOSURE | Set auto exposure for the region. |
| KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONFIG_WB | Set auto white balance for the region. |
| KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONVERGEMODE | Enable convergence of objects in the region. |

## See also

[KSPROPERTY_CAMERACONTROL_FLASH_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-flash-property)

[**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)