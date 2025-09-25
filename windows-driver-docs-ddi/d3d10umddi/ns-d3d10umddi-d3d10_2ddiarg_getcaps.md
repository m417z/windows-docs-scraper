# D3D10_2DDIARG_GETCAPS structure

## Description

The D3D10_2DDIARG_GETCAPS structure contains display device capabilities of a particular type.

## Members

### `Type` [in]

The type of capabilities to retrieve. The Microsoft Direct3D runtime can supply one of the values from the [D3D10_2DDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_2ddicaps_type) enumeration, possibly along with information in the memory block that is pointed to by **pInfo**, to retrieve particular capability data in the memory block at **pData**.

### `pInfo` [in]

A pointer to a memory block that contains data that specifies the specific condition on which to retrieve the capabilities of the type that is specified by the **Type** member.

### `pData` [out]

A pointer to a memory block that is filled with capabilities of the type that is specified by the **Type** member and possibly determined by the condition that is specified in the memory block at **pInfo**.

### `DataSize` [in/out]

The size, in bytes, of the memory block at **pData**.

## See also

[D3D10_2DDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_2ddicaps_type)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)