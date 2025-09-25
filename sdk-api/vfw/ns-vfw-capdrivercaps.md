# CAPDRIVERCAPS structure

## Description

The **CAPDRIVERCAPS** structure defines the capabilities of the capture driver.

An application should use the [WM_CAP_DRIVER_GET_CAPS](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-driver-get-caps) message or [capDriverGetCaps](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capdrivergetcaps) macro to place a copy of the driver capabilities in a **CAPDRIVERCAPS** structure whenever the application connects a capture window to a capture driver.

## Members

### `wDeviceIndex`

Index of the capture driver. An index value can range from 0 to 9.

### `fHasOverlay`

Video-overlay flag. The value of this member is **TRUE** if the device supports video overlay.

### `fHasDlgVideoSource`

Video source dialog flag. The value of this member is **TRUE** if the device supports a dialog box for selecting and controlling the video source.

### `fHasDlgVideoFormat`

Video format dialog flag. The value of this member is **TRUE** if the device supports a dialog box for selecting the video format.

### `fHasDlgVideoDisplay`

Video display dialog flag. The value of this member is **TRUE** if the device supports a dialog box for controlling the redisplay of video from the capture frame buffer.

### `fCaptureInitialized`

Capture initialization flag. The value of this member is **TRUE** if a capture device has been successfully connected.

### `fDriverSuppliesPalettes`

Driver palette flag. The value of this member is **TRUE** if the driver can create palettes.

### `hVideoIn`

Not used in Win32 applications.

### `hVideoOut`

Not used in Win32 applications.

### `hVideoExtIn`

Not used in Win32 applications.

### `hVideoExtOut`

Not used in Win32 applications.

## See also

Video Capture

[Video Capture Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-structures)