# _SCANINFO structure

## Description

The SCANINFO structure is used to store and communicate information about a scan acquisition. The WIA Flatbed Driver reads values from the SCANINFO structure, but never writes values. It is the microdriver's responsibility to set values for the SCANINFO members.

## Members

### `ADF`

Indicates whether the scanner supports an automatic document feeder (ADF). This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| 0 | The scanner does not support an ADF. |
| 1 | The scanner supports an ADF. |
| 2 | The scanner supports an ADF with duplex capability. |

### `TPA`

Indicates whether the scanner supports TPA (TransParency Adapter). The value can be:

0 - not supported

1 - supported

### `Endorser`

Indicates whether the scanner has endorser capabilities. The value can be:

0 - not supported

1 - supported

### `OpticalXResolution`

Specifies the horizontal dpi setting of the scanner optics.

### `OpticalYResolution`

Specifies the vertical dpi setting of the scanner optics.

### `BedWidth`

Specifies the bed width of the scanner in thousandths of an inch.

### `BedHeight`

Specifies the bed height of the scanner in thousandths of an inch.

### `IntensityRange`

Specifies the intensity/brightness range values of the scanner.

### `ContrastRange`

Specifies the contrast range values of the scanner.

### `SupportedCompressionType`

Specifies a mask value of supported compression types. A value of zero indicates that no compression types are supported.

### `SupportedDataTypes`

Specifies a mask value of supported data types. A value of zero indicates that no data types are supported. This member can be the bitwise OR of the following.

| Value | Meaning |
| --- | --- |
| SUPPORT_BW |The image is 1 bit-per-pixel black and white. |
| SUPPORT_COLOR | The image is 24 bits-per-pixel color. |
| SUPPORT_GRAYSCALE | The image is 8 bits-per-pixel grayscale. |

### `WidthPixels`

Specifies the width of the current image in pixels.

### `WidthBytes`

Specifies the width of the current image in bytes.

### `Lines`

Specifies the height of the current image in pixels.

### `DataType`

Specifies the current data type set of the current image. This member can be set to one of the following.

| Value | Meaning |
| --- | --- |
| WIA_DATA_COLOR | The driver supports 24 bit-per-pixel color. |
| WIA_DATA_COLOR_DITHER | This value is not supported in the WIA Flatbed driver. |
| WIA_DATA_COLOR_THRESHOLD | This value is not supported in the WIA Flatbed driver. |
| WIA_DATA_DITHER | This value is not supported in the WIA Flatbed driver. |
| WIA_DATA_GRAYSCALE | The driver supports 8 bit-per-pixel grayscale. |
| WIA_DATA_THRESHOLD | The driver supports 1 bit-per-pixel black and white. |

### `PixelBits`

Specifies the current bit depth setting of the current image.

### `Intensity`

Specifies the current intensity/brightness setting of the scanner.

### `Contrast`

Specifies the current contrast setting of the scanner.

### `Xresolution`

Specifies the horizontal dpi setting of the scanner optics.

### `Yresolution`

Specifies the vertical dpi setting of the scanner optics.

### `Window`

Specifies the current scanner window settings.

### `DitherPattern`

Specifies the dither pattern of the scanner.

### `Negative`

Specifies whether negative is on or off. The value can be:

0 - off

1 - on

### `Mirror`

Specifies whether mirror is on or off. The value can be:

0 - off

1 - on

### `AutoBack`

Specifies whether AutoBack is on or off. The value can be:

0 - off

1 - on

### `ColorDitherPattern`

Reserved. Set to zero.

### `ToneMap`

Reserved. Set to zero.

### `Compression`

Specifies whether compression is on or off for the scanner. The value can be:

0 - off

1 - on

### `RawDataFormat`

Specifies the raw data format for the scanner. The value can be:

0 - packed data

1 - planar data

### `RawPixelOrder`

Specifies the pixel order for the scanner. The value can be:

0 - RGB

1 - BGR

### `bNeedDataAlignment`

Specifies whether data alignment is needed for the scanner. The value can be:

0 - false

1 - true

### `DelayBetweenRead`

Specifies the time delay in milliseconds between [Scan](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/security-malware-windows-defender-scan) function calls that the scanner can support.

### `MaxBufferSize`

Specifies the maximum buffer size in the scanner.

### `DeviceIOHandles`

Specifies an array of device I/O handles needed for device communication.

### `lReserved`

Specifies an array of reserved bits.

### `pMicroDriverContext`

Points to the microdriver's context. The microdriver allocates the buffer pointed to by this member. The buffer should be allocated in CMD_INITIALIZE, and freed in CMD_UNINITIALIZE. (See [Required Commands](https://learn.microsoft.com/windows-hardware/drivers/image/required-commands).) The WIA Flatbed driver knows nothing of this pointer, and hence will not alter the memory pointed to by this member.

## Remarks

This structure is used as a parameter in the microdriver's [SetPixelWindow](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/nf-wiamicro-setpixelwindow), and [Scan](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/security-malware-windows-defender-scan) functions.

## See also

[Scan](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/security-malware-windows-defender-scan)

[SetPixelWindow](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/nf-wiamicro-setpixelwindow)