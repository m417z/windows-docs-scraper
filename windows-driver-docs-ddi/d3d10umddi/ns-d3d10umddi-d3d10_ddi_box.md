# D3D10_DDI_BOX structure

## Description

The D3D10_DDI_BOX structure describes a volume.

## Members

### `left` [in]

The position of the left side of the box on the x-axis.

### `top` [in]

The position of the top of the box on the y-axis.

### `front`

 [in] The position of the front of the box on the z-axis.

### `right` [in]

The position of the right side of the box on the x-axis. Note that the width of the volume equals the value in the **right** member minus the value in the **left** member (that is, width = right – left).

### `bottom` [in]

The position of the bottom of the box on the y-axis. Note that the height of the volume equals the value in the **bottom** member minus the value in the **top** member (that is, height = bottom – top).

### `back` [in]

The position of the back of the box on the z-axis. Note that the depth of the volume equals the value in the **back** member minus the value in the **front** member (that is, depth = back – front).

## See also

[ResourceCopyRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopyregion)