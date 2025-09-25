# DWMNCRENDERINGPOLICY enumeration

## Description

Flags used by the [DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) function to specify the non-client area rendering policy.

## Constants

### `DWMNCRP_USEWINDOWSTYLE`

The non-client rendering area is rendered based on the window style.

### `DWMNCRP_DISABLED`

The non-client area rendering is disabled; the window style is ignored.

### `DWMNCRP_ENABLED`

The non-client area rendering is enabled; the window style is ignored.

### `DWMNCRP_LAST`

The maximum recognized [DWMNCRENDERINGPOLICY](https://learn.microsoft.com/windows/desktop/api/dwmapi/ne-dwmapi-dwmncrenderingpolicy) value, used for validation purposes.

## Remarks

To use a **DWMNCRENDERINGPOLICY** value, set the *dwAttribute* parameter of the [DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) function to **DWMWA_NCRENDERING_POLICY**. Set the *pvAttribute* parameter to the **DWMNCRENDERINGPOLICY** value.