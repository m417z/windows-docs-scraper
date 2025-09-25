# IApplicationDesignModeSettings::IsApplicationViewStateSupported

## Description

Determines whether a particular application view state is supported for specific spoofed display size and scale factor settings.

You must call [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) to set a proxy core window before calling this method. For a code example, see [Display WinRT UI objects that depend on CoreWindow](https://learn.microsoft.com/windows/apps/develop/ui-input/display-ui-objects#winui-3-with-c).

## Parameters

### `viewState` [in]

One of the enumeration values that indicates the application view state for which support is being determined.

### `nativeDisplaySizePixels` [in]

The native size of the display to spoof.

### `scaleFactor` [in]

One of the enumeration values that indicates the device scale factor to spoof.

### `supported` [out]

When this method returns successfully, receives a pointer to a Boolean value which is set to **TRUE** if the application view state is supported for the given display size and scale factor, and **FALSE** if it is not.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

| Return code | Description |
| --- | --- |
| **E_NOT_SET** | [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) has not been called to set a proxy core window. |

## See also

[IApplicationDesignModeSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings)