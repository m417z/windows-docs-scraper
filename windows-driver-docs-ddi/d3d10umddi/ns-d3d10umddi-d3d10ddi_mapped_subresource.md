# D3D10DDI_MAPPED_SUBRESOURCE structure

## Description

The D3D10DDI_MAPPED_SUBRESOURCE structure describes a subresource that the driver maps to through a call to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function.

## Members

### `pData` [out]

A pointer to a buffer that contains the contents of the subresource.

### `RowPitch` [out]

The row pitch, width, or physical size (in bytes) of the data.

### `DepthPitch` [out]

The depth pitch, width, or physical size (in bytes) of the data.

## Remarks

The **pData** member points to row 0 and slice 0.

The **RowPitch** member is the value that is added to **pData** to move from row to row. Each row should contain multiple pixels.

The **DepthPitch** member is the value that is added to **pData** to move from depth slice to depth slice. Each depth slice should contain multiple rows.

It is not advisable to assign a value of zero to the **RowPitch** and **DepthPitch** members.

To avoid zero values for these members, it helps to think of all resources as being three-dimensional, as in these two examples:

* If the [resource attribute](https://learn.microsoft.com/windows-hardware/drivers/display/details-of-the-extended-format) is Buffer or Texture1D and contains 8 bytes, then appropriate values for **RowPitch** and **DepthPitch** would be 8 or more.
* If the [resource attribute](https://learn.microsoft.com/windows-hardware/drivers/display/details-of-the-extended-format) is Texture2d, even if **DepthPitch** is not used, **DepthPitch** must not be assigned a value of zero.

## See also

[ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap)