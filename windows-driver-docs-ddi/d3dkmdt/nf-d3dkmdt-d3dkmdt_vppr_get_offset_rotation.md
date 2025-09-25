# D3DKMDT_VPPR_GET_OFFSET_ROTATION function

## Description

A helper function that extracts the offset angle from a given value of the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation) enumeration. Only drivers that support path-independent rotation (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM1_3_PATH_INDEPENDENT_ROTATION) should call this function.

## Parameters

### `Rotation`

On input, a value from the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation) enumeration.

On output, a value between 1 and 4, inclusive, that corresponds to the **OFFSET** portion of the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation) constant values. An output value of 1 (identity) represents 0 degrees of offset, 2 represents 90 degrees, and so on. An output value of 0 indicates that the VidPN path is not initialized.

The output value is always one of the supported values specified for this path in the [D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation_support) structure.

## Return value

The returned value corresponds to the offset angle as follows:

|Input enumeration value|Input enumeration constant|Offset in degrees|Output Rotation value|
|--- |--- |--- |--- |
|0|D3DKMDT_VPPR_UNINITIALIZED|-|0|
|1|D3DKMDT_VPPR_IDENTITY|0|1|
|2|D3DKMDT_VPPR_ROTATE90|0|1|
|3|D3DKMDT_VPPR_ROTATE180|0|1|
|4|D3DKMDT_VPPR_ROTATE270|0|1|
|5|D3DKMDT_VPPR_IDENTITY_OFFSET90|90|2|
|6|D3DKMDT_VPPR_ROTATE90_OFFSET90|90|2|
|7|D3DKMDT_VPPR_ROTATE180_OFFSET90|90|2|
|8|D3DKMDT_VPPR_ROTATE270_OFFSET90|90|2|
|9|D3DKMDT_VPPR_IDENTITY_OFFSET180|180|3|
|10|D3DKMDT_VPPR_ROTATE90_OFFSET180|180|3|
|11|D3DKMDT_VPPR_ROTATE180_OFFSET180|180|3|
|12|D3DKMDT_VPPR_ROTATE270_OFFSET180|180|3|
|13|D3DKMDT_VPPR_IDENTITY_OFFSET270|270|4|
|14|D3DKMDT_VPPR_ROTATE90_OFFSET270|270|4|
|15|D3DKMDT_VPPR_ROTATE180_OFFSET270|270|4|
|16|D3DKMDT_VPPR_ROTATE270_OFFSET270|270|4|

## Remarks

This function is declared inline in D3dkmdt.h as:

```cpp
__inline
D3DKMDT_VIDPN_PRESENT_PATH_ROTATION
    D3DKMDT_VPPR_GET_OFFSET_ROTATION(
        D3DKMDT_VIDPN_PRESENT_PATH_ROTATION Rotation)
{
    if ((Rotation >= D3DKMDT_VPPR_IDENTITY) &&
        (Rotation <= D3DKMDT_VPPR_ROTATE270_OFFSET270))
    {
        Rotation = (D3DKMDT_VIDPN_PRESENT_PATH_ROTATION)(
            ((Rotation - 1) / 4) + 1);
    }
    return Rotation;
}
```

The driver should use the output value of the *Rotation* parameter to rotate the secondary clone path content when the Desktop Window Manager (DWM) has already rotated the primary clone path content. For more info, see [Supporting Path-Independent Rotation](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-path-independent-rotation).

## See also

[D3DKMDT_VIDPN_PRESENT_PATH_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation)

[D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_rotation_support)