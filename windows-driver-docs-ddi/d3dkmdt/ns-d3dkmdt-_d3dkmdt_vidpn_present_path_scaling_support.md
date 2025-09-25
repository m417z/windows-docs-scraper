# _D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT structure

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT structure is used to indicate the types of scaling (and centering) that are supported by a particular VidPN present path.

## Members

### `Identity`

The path is capable of displaying content with no transformation.

### `Centered`

The path is capable of displaying centered content.

### `Stretched`

The path is capable of displaying scaled content.

### `AspectRatioCenteredMax`

The path is capable of scaling source content to fit the target while preserving the aspect ratio of the source.

This member is available beginning with Windows 7.

### `Custom`

The path is capable of displaying one or more scaling modes that are not described by other members of this structure.

## Remarks

The **ScalingSupport** member of a [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) structure is a D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT structure.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH_SCALING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_scaling)

[D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation)