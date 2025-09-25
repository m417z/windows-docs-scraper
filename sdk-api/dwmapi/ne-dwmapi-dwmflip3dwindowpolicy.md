# DWMFLIP3DWINDOWPOLICY enumeration

## Description

Flags used by the [DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) function to specify the Flip3D window policy.

## Constants

### `DWMFLIP3D_DEFAULT`

Use the window's style and visibility settings to determine whether to hide or include the window in Flip3D rendering.

### `DWMFLIP3D_EXCLUDEBELOW`

Exclude the window from Flip3D and display it below the Flip3D rendering.

### `DWMFLIP3D_EXCLUDEABOVE`

Exclude the window from Flip3D and display it above the Flip3D rendering.

### `DWMFLIP3D_LAST`

The maximum recognized [DWMFLIP3DWINDOWPOLICY](https://learn.microsoft.com/windows/desktop/api/dwmapi/ne-dwmapi-dwmflip3dwindowpolicy) value, used for validation purposes.

## Remarks

To use a **DWMFLIP3DWINDOWPOLICY** value, set the *dwAttribute* parameter of the [DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) function to **DWMWA_FLIP3D_POLICY**. Set the *pvAttribute* parameter to the **DWMFLIP3DWINDOWPOLICY** value.

## See also

[Enable and Control DWM Composition](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw)