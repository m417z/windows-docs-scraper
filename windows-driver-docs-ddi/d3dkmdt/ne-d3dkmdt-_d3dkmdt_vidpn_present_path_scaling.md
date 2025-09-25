# _D3DKMDT_VIDPN_PRESENT_PATH_SCALING enumeration

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_SCALING enumeration is used to indicate the scaling transformation applied to content displayed on a VidPN present path.

## Constants

### `D3DKMDT_VPPS_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_VIDPN_PRESENT_PATH_SCALING has not yet been assigned a meaningful value.

### `D3DKMDT_VPPS_IDENTITY`

Indicates the identity transformation; the source content is presented with no change. Note that this transformation is available only if the path's source mode has the same spatial resolution as the path's target mode.

### `D3DKMDT_VPPS_CENTERED`

Indicates the centering transformation; the source content is presented unscaled, centered with respect to the spatial resolution of the target mode.

### `D3DKMDT_VPPS_STRETCHED`

Indicates that the source content is scaled to fit the path's target, and the aspect ratio of the source is not preserved.

### `D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX`

Indicates that the source content is scaled to fit the path's target while preserving the aspect ratio of the source.

This constant value is available beginning with Windows 7. See further information in the Remarks section.

### `D3DKMDT_VPPS_CUSTOM`

Indicates that the path is capable of displaying one or more scaling modes that are not described by other constants of this enumeration.

This constant value is available beginning with Windows 7. See further information in the Remarks section.

### `D3DKMDT_VPPS_RESERVED1`

Reserved for system use. Do not use this value. This value will never be passed to a driver.

This constant value is available beginning with Windows 7.

### `D3DKMDT_VPPS_UNPINNED`

Indicates that no scaling transformation has been pinned for the VidPN present source.

### `D3DKMDT_VPPS_NOTSPECIFIED`

Indicates that no transformation has been specified. See further information in the Remarks section.

## Remarks

The **Scaling** member of the [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) structure is a value from the D3DKMDT_VIDPN_PRESENT_PATH_SCALING enumeration.

If D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX or D3DKMDT_VPPS_CUSTOM values are specified but the path is on a display miniport driver that does not support these values (which are available beginning with Windows 7), the driver's calls to [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) should return STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED, and the operating system will apply the system default scaling. If a driver cannot support the requested scaling value on the specified path, its calls to **DxgkDdiCommitVidPn** should return STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED.

**Note** A display miniport driver that supports the D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX or D3DKMDT_VPPS_CUSTOM values should never set a value of D3DKMDT_VPPS_NOTSPECIFIED.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_scaling_support)

[DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn)