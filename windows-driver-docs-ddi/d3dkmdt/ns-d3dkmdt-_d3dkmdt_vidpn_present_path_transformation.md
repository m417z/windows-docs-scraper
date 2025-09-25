# _D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION structure

## Description

The **D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION** structure contains information about the transformations (for example, rotation, scaling, centering) that are pinned and the transformations that are supported for a path in a video present network (VIDPN).

## Members

### `Scaling`

A value from the [D3DKMDT_VIDPN_PRESENT_PATH_SCALING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_scaling) enumeration that indicates the type of scaling (or centering) that is currently set for the path. If this member is equal to **D3DKMDT_VPPS_IDENTITY**, **D3DKMDT_VPPS_CENTERED**, **D3DKMDT_VPPS_STRETCHED**, **D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX**, or **D3DKMDT_VPPS_CUSTOM**, then the indicated scaling type is considered pinned for the path. If this member is equal to any other value, then no scaling type is pinned for the path.

For more information on how to use this member, see the Remarks section.

### `ScalingSupport`

A [D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_scaling_support) structure that holds a set of flags that indicate the types of scaling that are supported by the path.

### `Rotation`

A value from the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation) enumeration that indicates the type of rotation that is currently set for the path. If this member is equal to **D3DKMDT_VPPR_IDENTITY**, **D3DKMDT_VPPR_ROTATE90**, **D3DKMDT_VPPR_ROTATE180** or **D3DKMDT_VPPR_ROTATE270**, then the indicated rotation type is considered pinned for the path. If this member is equal to any other value, then no rotation type is pinned for the path.

### `RotationSupport`

A [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation_support) structure that holds a set of flags that indicate the types of rotation that are supported by the path.

## Remarks

The **ContentTransformation** member of the [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure is a **D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION** structure.

If **D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX** or **D3DKMDT_VPPS_CUSTOM** values are specified in the **Scaling** member but the path is on a display miniport driver that does not support these values (which are available beginning with Windows 7), the driver's calls to [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) should return **STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED**, and the operating system will apply the system default scaling. If a driver cannot support the requested scaling value on the specified path, its calls to **DxgkDdiCommitVidPn** should return **STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED**.

**Note** A display miniport driver that supports the **D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX** or **D3DKMDT_VPPS_CUSTOM** values should never set a value of **D3DKMDT_VPPS_NOTSPECIFIED**.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation)

[D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation_support)

[D3DKMDT_VIDPN_PRESENT_PATH_SCALING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_scaling)

[D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_scaling_support)

[DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn)

[DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)