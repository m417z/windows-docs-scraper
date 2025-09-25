# tagKS_AMVPDATAINFO structure

## Description

The KS_AMVPDATAINFO structure is used to describe the properties of a video port.

## Members

### `dwSize`

Specifies the size of the structure, in bytes.

### `dwMicrosecondsPerField`

Specifies the time taken by each field, in microseconds (millionths of a second).

### `amvpDimInfo`

Describes the dimensional information of the video port, such as field and VBI dimensions.

### `dwPictAspectRatioX`

Indicates the picture aspect ratio in the horizontal dimension. For example, for a 16x9 aspect ratio this member would be 16.

### `dwPictAspectRatioY`

Indicates the picture aspect ratio in the vertical dimension. For example, for a 4x3 aspect ratio this member would be 3.

### `bEnableDoubleClock`

Specifies if the video port should enable double clocking.

### `bEnableVACT`

Specifies if the video port should use an external VACT signal.

### `bDataIsInterlaced`

Indicates that the signal is interlaced.

### `lHalfLinesOdd`

Indicates the number of halflines in the odd field.

### `bFieldPolarityInverted`

Indicates if the device inverts the field polarity by default.

### `dwNumLinesInVREF`

Specifies the number of lines of data in VREF.

### `lHalfLinesEven`

Indicates the number of halflines in the even field.

### `dwReserved1`

Reserved for future use. Do not use.

## Remarks

This structure is used by the [KSPROPERTY_VPCONFIG_VPDATAINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-vpconfig-vpdatainfo) property.

## See also

[KSPROPERTY_VPCONFIG_VPDATAINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-vpconfig-vpdatainfo)