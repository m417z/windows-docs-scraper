# IApplicationDesignModeSettings::ComputeApplicationSize

## Description

Gets the size of the Windows Store app, based on the current set of spoofed settings.

You must call [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) to set a proxy core window before calling this method. For a code example, see [Display WinRT UI objects that depend on CoreWindow](https://learn.microsoft.com/windows/apps/develop/ui-input/display-ui-objects#winui-3-with-c).

In addition, each of these methods must be called before calling **ComputeApplicationSize**, or the call will fail.

* [SetApplicationViewState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-setapplicationviewstate)
* [SetNativeDisplaySize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-setnativedisplaysize)
* [SetScaleFactor](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-setscalefactor)

## Parameters

### `applicationSizePixels` [out]

When this method returns successfully, receives a pointer to the size that the Windows Store app should occupy, based on the current set of spoofed settings.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

| Return code | Description |
| --- | --- |
| **E_NOT_SET** | [IInitializeWithWindow::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithwindow-initialize) has not been called to set a proxy core window. |

## See also

[IApplicationDesignModeSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings)