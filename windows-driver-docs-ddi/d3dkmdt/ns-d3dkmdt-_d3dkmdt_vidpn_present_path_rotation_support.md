# _D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT structure

## Description

The **D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT** structure is used to indicate the angles of rotation that are supported by a particular VidPN present path.

## Members

### `Identity`

The path is capable of displaying content with no rotation.

### `Rotate90`

The path is capable of displaying content that is rotated 90 degrees.

### `Rotate180`

The path is capable of displaying content that is rotated 180 degrees.

### `Rotate270`

The path is capable of displaying content that is rotated 270 degrees.

### `Offset0`

The path adds no rotational offset. For more info, see [Clone-mode requirements starting with Windows 8.1 Update](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-rotation-in-a-display-miniport-driver).

Supported starting with Windows 8.1 Update.

### `Offset90`

The path adds a rotational offset of 90 degrees. For more info, see [Clone-mode requirements starting with Windows 8.1 Update](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-rotation-in-a-display-miniport-driver).

Supported starting with Windows 8.1 Update.

### `Offset180`

The path adds a rotational offset of 180 degrees. For more info, see [Clone-mode requirements starting with Windows 8.1 Update](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-rotation-in-a-display-miniport-driver).

Supported starting with Windows 8.1 Update.

### `Offset270`

The path adds a rotational offset of 270 degrees. For more info, see [Clone-mode requirements starting with Windows 8.1 Update](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-rotation-in-a-display-miniport-driver).

Supported starting with Windows 8.1 Update.

## Remarks

The **RotationSupport** member of the [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) structure is a **D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT** structure.

**Note** The operating system does not update the value of the interface version value **DXGKDDI_INTERFACE_VERSION** to **DXGKDDI_INTERFACE_VERSION_WDDM1_3_PATH_INDEPENDENT_ROTATION**. If you want to use the path-independent members in this structure, you should be sure that the interface version in your driver is >= **DXGKDDI_INTERFACE_VERSION_WDDM1_3_PATH_INDEPENDENT_ROTATION** (0x4003).