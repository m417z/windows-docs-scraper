# IApplicationDesignModeSettings::SetScaleFactor

## Description

Sets a spoofed device scale factor to be used for a Windows Store app running in design mode.

You must call [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) to set a proxy core window before calling this method. For a code example, see [Display WinRT UI objects that depend on CoreWindow](https://learn.microsoft.com/windows/apps/develop/ui-input/display-ui-objects#winui-3-with-c).

**SetScaleFactor** must be called before calling [ComputeApplicationSize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-computeapplicationsize).

## Parameters

### `scaleFactor` [in]

One of the [DEVICE_SCALE_FACTOR](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-device_scale_factor) enumeration values that indicates the device scale factor to spoof.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

| Return code | Description |
| --- | --- |
| **E_NOT_SET** | [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) has not been called to set a proxy core window. |

## See also

[IApplicationDesignModeSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings)