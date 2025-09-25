# IApplicationDesignModeSettings2::SetNativeDisplayOrientation

## Description

Sets the orientation of the emulated display for the design mode window.

## Parameters

### `nativeDisplayOrientation` [in]

Type: **NATIVE_DISPLAY_ORIENTATION**

The native orientation of the display to emulate.

#### NDO_LANDSCAPE (0)

Landscape orientation, with the display width greater than the height.

#### NDO_PORTRAIT (1)

Portrait orientation, with the display height greater than the width.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationDesignModeSettings2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings2)