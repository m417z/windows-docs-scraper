# _D3DDDIARG_GETCAPS structure

## Description

The D3DDDIARG_GETCAPS structure contains display device capabilities of a particular type.

## Members

### `Type` [in]

The type of capabilities to retrieve. The Microsoft Direct3D runtime can supply one of the values from the [D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type) enumeration type, possibly along with information in the buffer that is pointed to by **pInfo**, to retrieve particular capability data in the buffer at **pData**.

### `pInfo` [in]

A pointer to a buffer that contains data that specifies the specific condition on which to retrieve the capabilities of the type that is specified by the **Type** member.

### `pData` [out]

A pointer to a buffer that is filled with capabilities of the type that is specified by the **Type** member and possibly determined by the condition that is specified in the buffer at **pInfo**.

### `DataSize` [in/out]

The size, in bytes, of the buffer at **pData**.

## Remarks

For information on how to specify **D3DDDIARG_GETCAPS** member values along with [D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type) constant values, see Remarks of [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps).

## See also

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)