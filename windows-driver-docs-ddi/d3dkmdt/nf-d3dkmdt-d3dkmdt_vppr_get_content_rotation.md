# D3DKMDT_VPPR_GET_CONTENT_ROTATION function

## Description

A helper function that extracts the combined rotation that the user sees from the default display orientation from a given value of the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation) enumeration. This value is effectively the sum of the offset angle and the angle that the Desktop Window Manager (DWM) has already rotated the primary clone path content. Only drivers that support path-independent rotation (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM1_3_PATH_INDEPENDENT_ROTATION) should call this function.

## Parameters

### `Rotation`

On input, a value from the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation) enumeration.

On output, a value between 1 and 4, inclusive, that corresponds to the **OFFSET** portion of the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation) constant values. An output value of 1 (identity) represents 0 degrees of total rotation, 2 represents 90 degrees, and so on. An output value of 0 indicates that the VidPN path is not initialized.

The output value of *Rotation* is the sum of the output values from the [D3DKMDT_VPPR_GET_CONTENT_ROTATION_PART](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/nf-d3dkmdt-d3dkmdt_vppr_get_content_rotation_part) and [D3DKMDT_VPPR_GET_OFFSET_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/nf-d3dkmdt-d3dkmdt_vppr_get_offset_rotation) functions minus 1.

## Return value

The returned value corresponds to the rotation and offset angles as follows:

|Input enumeration value|Input enumeration constant|Rotation + offset, in degrees|Output Rotation value|
|--- |--- |--- |--- |
|0|D3DKMDT_VPPR_UNINITIALIZED|-|0|
|1|D3DKMDT_VPPR_IDENTITY|0|1|
|2|D3DKMDT_VPPR_ROTATE90|90|2|
|3|D3DKMDT_VPPR_ROTATE180|180|3|
|4|D3DKMDT_VPPR_ROTATE270|270|4|
|5|D3DKMDT_VPPR_IDENTITY_OFFSET90|90|2|
|6|D3DKMDT_VPPR_ROTATE90_OFFSET90|180|3|
|7|D3DKMDT_VPPR_ROTATE180_OFFSET90|270|4|
|8|D3DKMDT_VPPR_ROTATE270_OFFSET90|0|1|
|9|D3DKMDT_VPPR_IDENTITY_OFFSET180|180|3|
|10|D3DKMDT_VPPR_ROTATE90_OFFSET180|270|4|
|11|D3DKMDT_VPPR_ROTATE180_OFFSET180|0|1|
|12|D3DKMDT_VPPR_ROTATE270_OFFSET180|90|2|
|13|D3DKMDT_VPPR_IDENTITY_OFFSET270|270|4|
|14|D3DKMDT_VPPR_ROTATE90_OFFSET270|0|1|
|15|D3DKMDT_VPPR_ROTATE180_OFFSET270|90|2|
|16|D3DKMDT_VPPR_ROTATE270_OFFSET270|180|3|

## Remarks

This function is declared inline in D3dkmdt.h as:

```cpp
__inline
D3DKMDT_VIDPN_PRESENT_PATH_ROTATION
    D3DKMDT_VPPR_GET_CONTENT_ROTATION(
        D3DKMDT_VIDPN_PRESENT_PATH_ROTATION Rotation)
{
    if ((Rotation >= D3DKMDT_VPPR_IDENTITY_OFFSET90) &&
        (Rotation <= D3DKMDT_VPPR_ROTATE270_OFFSET270))
    {
        D3DKMDT_VIDPN_PRESENT_PATH_ROTATION ContentPart =
            D3DKMDT_VPPR_GET_CONTENT_ROTATION_PART(Rotation);
        D3DKMDT_VIDPN_PRESENT_PATH_ROTATION OffsetPart =
            D3DKMDT_VPPR_GET_OFFSET_ROTATION(Rotation);
        Rotation = (D3DKMDT_VIDPN_PRESENT_PATH_ROTATION)(
            (((ContentPart - 1) + (OffsetPart - 1)) % 4) + 1);
    }
    return Rotation;
}
```

If the content being presented has to be rotated by the driver, the output of this function represents the total rotation (the **Rotate** member of the [DXGK_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentflags) structure) that the driver needs to apply to the pixels provided in the [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) operation. For more info, see [Supporting Path-Independent Rotation](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-path-independent-rotation).

Here's an example of how this function can provide your driver with the info it needs to properly rotate content. When a portrait-first device is connected in clone mode to a landscape-first monitor and the user changes the **Orientation** in the **Display** control panel to **Portrait**, this represents the default orientation of the portrait-first device. Therefore the driver should set a value of [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation).**D3DKMDT_VPPR_ROTATE90_OFFSET270** on the path. This function will then return a *Rotation* value of 1 (identity) to indicate that the content displayed on the clone path is not to be rotated.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation)

[D3DKMDT_VPPR_GET_CONTENT_ROTATION_PART](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/nf-d3dkmdt-d3dkmdt_vppr_get_content_rotation_part)

[D3DKMDT_VPPR_GET_OFFSET_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/nf-d3dkmdt-d3dkmdt_vppr_get_offset_rotation)

[DXGK_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentflags)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)