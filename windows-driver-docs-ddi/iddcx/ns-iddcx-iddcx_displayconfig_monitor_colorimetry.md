## Description

The **IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY** structure contains colorimetry information for a monitor.

## Members

### `RedPoint`

A [**DISPLAYCONFIG_2DREGION**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that contains an override for the display red point. Each dimension is a 10-bit value stored in the least significant bits. Zero indicates no override.

### `GreenPoint`

A [**DISPLAYCONFIG_2DREGION**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that contains an override for the display green point. Each dimension is a 10-bit value stored in the least significant bits.

### `BluePoint`

A [**DISPLAYCONFIG_2DREGION**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that contains an override for the display blue point. Each dimension is a 10-bit value stored in the least significant bits.

### `WhitePoint`

A [**DISPLAYCONFIG_2DREGION**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that contains an override for the display white point. Each dimension is a 10-bit value stored in the least significant bits.

### `MinLuminance`

Override for the minimum luminance value supported by the display, measured in one ten thousandth of a nit. Zero is a valid value. **MinLuminance** is valid only if MaxLuminance is non-zero.

### `MaxLuminance`

Override for the maximum luminance value supported by the display, measured in one ten thousandth of a nit. This luminance level is expected to be supported for only a relatively small area in any given frame. Zero indicates no override of **MaxLuminance**, **MaxFullFrameLuminance** or **MinLuminance**.

### `MaxFullFrameLuminance`

Override for the maximum full frame luminance value supported by the display, measured in one ten thousandth of a nit. This luminance level must be supported across every pixel in the frame simultaneously in order to provide an estimate of the average luminance value that the display can support across a frame. **MaxFullFrameLuminance** is only valid if **MaxLuminance** is non-zero. Zero is not a valid override.

### `BitsPerComponent`

A [**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component) structure that overrides the supported bits per color component in each of the color encodings specified. At least one bit must be set one of the color encodings.

### `Flags`

A bitwise OR of[**IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_displayconfig_monitor_colorimetry_flags) enumeration flags that indicates support for specific colorimetry and Electro-Optical Transfer Function (EOTF) capabilities.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate2)

[**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)