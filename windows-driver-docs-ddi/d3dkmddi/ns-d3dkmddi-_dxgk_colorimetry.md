# _DXGK_COLORIMETRY structure

## Description

Describes colorimetry and closely related fields used to describe overrides from the descriptor retrieved from the display device.

## Members

### `RedPoint`

Override for display red point. Note, each dimension is a 10-bit value stored in the least significant bits.
Zero indicates no override.

### `GreenPoint`

Override for display green point. Note, each dimension is a 10-bit value stored in the least significant bits.

### `BluePoint`

Override for display blue point. Note, each dimension is a 10-bit value stored in the least significant bits.

### `WhitePoint`

Override for display white point. Note, each dimension is a 10-bit value stored in the least significant bits.

### `MinLuminance`

Override for the minimum luminance value supported by the display measured in one ten thousandth of a nit. Only valid if MaxLuminance is non-zero. Zero is a valid value.

### `MaxLuminance`

Override for the maximum luminance value supported by the display measured in one ten thousandth of a nit. This luminance level is expected to be supported for only a relatively small area in any given frame.
Zero indicates no override of MaxLuminance, MaxFullFrameLuminance or MinLuminance.

### `MaxFullFrameLuminance`

Override for the max full frame luminance value supported by the display measured in one ten thousandth of a nit. This luminance level must be supported across every pixel in the frame simultaneously in order to provide an estimate of the average luminance value which can be supported by the display across a frame.
Only valid if MaxLuminance is non-zero. Zero is not a valid override.

### `FormatBitDepths`

Overrides the supported bits per color channel in each of the five color encodings specified for wire-formats. At least one bit must be set, excluding the Preference field which is reserved and must be zero.

### `StandardColorimetryFlags`

Indicates support for specific colorimetry and EOTF capabilities using bit-fields.

## Remarks

This struct is used both for querying overrides from the driver, and for the OS reporting the final set of values it has selected. Overrides are supported for integrated displays using this structure which is embedded within the DXGK_QUERYINTEGRATEDDISPLAYOUT struct and for external displays where this struct is used as the output buffer is for an adapter query type DXGKQAITYPE_QUERYCOLORIMETRYOVERRIDES. The selected and adjusted overrides are reported back to the driver using DxgkDdiSetTargetAdjustedColorimetry.

When querying overrides, the OS requires that either all fields are filled by the driver or the buffer is left zeroed to avoid the complexity of attempting to merge these inter-related attributes from different sources. If the struct is not completely zeroed, the OS validates that fields which must not be zero as noted above, are not zero.

The color points are further validated beyond a simple sanity check (each value must be between 1 and 1023) to ensure reasonable values by comparing the coordinates of each point to the standard points and ensuring that none is too far away from the standard.

When the OS calls DxgkDdiSetTargetAdjustedColorimetry, the FormatBitDepths and StandardColorimetryFlags are zeroed as these are capability fields so only valid in queries.