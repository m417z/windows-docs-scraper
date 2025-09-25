# _D3DKMDT_VIDPN_PRESENT_PATH_ROTATION enumeration

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_ROTATION enumeration is used to indicate the rotation angle applied to content displayed on a VidPN present path.

## Constants

### `D3DKMDT_VPPR_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_VIDPN_PRESENT_PATH_ROTATION has not yet been assigned a meaningful value.

### `D3DKMDT_VPPR_IDENTITY`

Indicates that there is no rotation.

### `D3DKMDT_VPPR_ROTATE90`

Indicates that the rotation angle is 90 degrees counter-clockwise.

### `D3DKMDT_VPPR_ROTATE180`

Indicates that the rotation angle is 180 degrees counter-clockwise.

### `D3DKMDT_VPPR_ROTATE270`

Indicates that the rotation angle is 270 degrees counter-clockwise.

### `D3DKMDT_VPPR_IDENTITY_OFFSET90`

Indicates that source content is not modified in any way, and the display miniport driver should rotate this content an extra 90 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE90_OFFSET90`

Indicates that source content is rotated 90 degrees counter-clockwise, and the driver should rotate this content an extra 90 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE180_OFFSET90`

Indicates that source content is rotated 180 degrees counter-clockwise, and the driver should rotate this content an extra 90 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE270_OFFSET90`

Indicates that source content is rotated 270 degrees counter-clockwise, and the driver should rotate this content an extra 90 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_IDENTITY_OFFSET180`

Indicates that source content is not modified in any way, and the driver should rotate this content an extra 180 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE90_OFFSET180`

Indicates that source content is rotated 90 degrees counter-clockwise, and the driver should rotate this content an extra 180 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE180_OFFSET180`

Indicates that source content is rotated 180 degrees counter-clockwise, and the driver should rotate this content an extra 180 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE270_OFFSET180`

Indicates that source content is rotated 270 degrees, and the driver should rotate this content an extra 180 degrees. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_IDENTITY_OFFSET270`

Indicates that source content is not modified in any way, and the driver should rotate this content an extra 270 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE90_OFFSET270`

Indicates that source content is rotated 90 degrees counter-clockwise, and the driver should rotate this content an extra 270 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE180_OFFSET270`

Indicates that source content is rotated 180 degrees counter-clockwise, and the driver should rotate this content an extra 270 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_ROTATE270_OFFSET270`

Indicates that source content is rotated 270 degrees counter-clockwise, and the driver should rotate this content an extra 270 degrees counter-clockwise. For more info, see Remarks.

Supported starting with Windows 8.1 Update.

### `D3DKMDT_VPPR_UNPINNED`

Indicates that no rotation angle has been pinned for the VidPN present path.

### `D3DKMDT_VPPR_NOTSPECIFIED`

Indicates that no rotation angle (including identity) has been specified.

## Remarks

The **Rotation** member of the [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) structure is a value from the **D3DKMDT_VIDPN_PRESENT_PATH_ROTATION** enumeration.

Starting with Windows 8.1 Update, new constant values (**D3DKMDT_VPPR_XXX_OFFSETXXX**) are available to specify both the default orientation of a display device and an additional angle (offset) that the user has rotated the device.

Here are some examples of how to set the default orientation and offset:

* If the topology is specified as:
  + a single monitor,
  + a non-path-independent rotation clone, or
  + a primary monitor for a path-independent rotation clone,use one of the enumeration values 1 through 4:
  + **D3DKMDT_VPPR_IDENTITY**
  + **D3DKMDT_VPPR_ROTATE90**
  + **D3DKMDT_VPPR_ROTATE180**
  + **D3DKMDT_VPPR_ROTATE270**
* For a path-independent rotation clone, the secondary monitor probably has **D3DKMDT_VPPR_XXX_OFFSET270** set if it is a portrait-first panel.
* Also consider these uncommon scenarios:
  + For a path-independent rotation clone, a landscape-first display panel connected to a portrait-first primary device will probably have **D3DKMDT_VPPR_XXX_OFFSET90** set.
  + For a path-independent rotation clone on a system prior to Windows 8.1, a landscape-first display panel connected to a landscape-first primary device will probably have **D3DKMDT_VPPR_XXX_OFFSET180** set.

**Note** The operating system does not update the value of the interface version value **DXGKDDI_INTERFACE_VERSION** to **DXGKDDI_INTERFACE_VERSION_WDDM1_3_PATH_INDEPENDENT_ROTATION**. If you want to use the path-independent members in this structure, you should be sure that the interface version in your driver is >= **DXGKDDI_INTERFACE_VERSION_WDDM1_3_PATH_INDEPENDENT_ROTATION** (0x4003).

## See also

[D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation)