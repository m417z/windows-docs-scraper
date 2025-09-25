# ColorMatchToTarget function

## Description

The **ColorMatchToTarget** function enables you to preview colors as they would appear on the target device.

## Parameters

### `hdc`

Specifies the device context for previewing, generally the screen.

### `hdcTarget`

Specifies the target device context, generally a printer.

### `action`

A constant that can have one of the following values.

| Value | Meaning |
| --- | --- |
| **CS_ENABLE** | Map the colors to the target device's color gamut. This enables color proofing. All subsequent draw commands to the DC will render colors as they would appear on the target device. |
| **CS_DISABLE** | Disable color proofing. |
| **CS_DELETE_TRANSFORM** | If color management is enabled for the target profile, disable it and delete the concatenated transform. |

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**.

## Remarks

**ColorMatchToTarget** can be used to proof the colors of a color output device on another color output device. Setting the *uiAction* parameter to CS_ENABLE causes all subsequent drawing commands to the DC to render colors as they would appear on the target device. If *uiAction* is set to CS_DISABLE, proofing is turned off. However, the current color transform is not deleted from the DC. It is just inactive.

When **ColorMatchToTarget** is called, the color transform for the target device is performed first, and then the transform to the preview device is applied to the results of the first transform. This is used primarily for checking gamut mapping conditions. Before using this function, you must enable WCS for both device contexts.

This function cannot be cascaded. While color mapping to the target is enabled by setting *uiAction* to CS_ENABLE, application changes to the color space or gamut mapping method are ignored. Those changes then take effect when color mapping to the target is disabled.

**Note** A memory leak will not occur if an application does not delete a transform using CS_DELETE_TRANSFORM. The transform will be deleted when either the device context (DC) is closed, or when the application color space is deleted. However if the transform is not going to be used again, or if the application will not be performing any more color matching on the DC, it should explicitly delete the transform to free the memory it occupies.

The *uiAction* parameter should only be set to CS_DELETE_TRANSFORM if color management is enabled before the **ColorMatchToTarget** function is called.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)