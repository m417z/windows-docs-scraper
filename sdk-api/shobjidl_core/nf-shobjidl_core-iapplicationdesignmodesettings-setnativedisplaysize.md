# IApplicationDesignModeSettings::SetNativeDisplaySize

## Description

Sets a spoofed native display size to be used for a Windows Store app running in design mode.

You must call [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) to set a proxy core window before calling this method. For a code example, see [Display WinRT UI objects that depend on CoreWindow](https://learn.microsoft.com/windows/apps/develop/ui-input/display-ui-objects#winui-3-with-c).

**SetNativeDisplaySize** must be called before calling [ComputeApplicationSize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-computeapplicationsize).

## Parameters

### `nativeDisplaySizePixels` [in]

The native size of the display to spoof, as a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure. The specified size will be normalized to a landscape orientation. To spoof orientation, see [SetApplicationViewState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-setapplicationviewstate).

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

| Return code | Description |
| --- | --- |
| **E_NOT_SET** | [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) has not been called to set a proxy core window. |
| **E_MONITOR_RESOLUTION_TOO_LOW** | You cannot launch or switch to an immersive app when the resolution is this low. This is currently defined as any resolution below 800 horizontal or 600 vertical pixels when in landscape orientation. |

## See also

[IApplicationDesignModeSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings)