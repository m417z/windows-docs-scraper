# PFND3DDDI_GETCAPS callback function

## Description

The D3D runtime calls the driver's **PFND3DDDI_GETCAPS** callback function to query the capabilities of the graphics adapter.

## Parameters

### `hAdapter`

A handle that identifies the graphics adapter.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure that describes the capabilities to retrieve.

## Return value

**PFND3DDDI_GETCAPS** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| S_OK | The capabilities were successfully retrieved.|
| E_OUTOFMEMORY | PFND3DDDI_GETCAPS could not allocate the required memory for it to complete.|

## Remarks

The data returned in the **pData** member of the [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure depends on the type of data that is requested (that is, the data depends on **D3DDDIARG_GETCAPS.Type** and sometimes on the **pInfo** member).

The following table has two examples of how to set up the **PFND3DDDI_GETCAPS** call depending on the value of [**D3DDDIARG_GETCAPS.Type**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).

| D3DDDIARG_GETCAPS member | Example 1 | Example 2 |
|:--|:--|:--|
| **Type** | **D3DDDICAPS_DDRAW** | **D3DDDICAPS_GETFORMATCOUNT** |
| **pInfo** | [in] NULL (no conditions are set) | [in] NULL (no conditions are set) |
| **pData** | [out] [**DDRAW_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddraw_caps) (unique pointer) | [out] UINT* (unique pointer) |
| **DataSize** | sizeof(DDRAW_CAPS) | sizeof(UINT) |
| Notes | Driver must fill in the [**DDRAW_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddraw_caps) structure with the DirectDraw capabilities that it supports. | Driver must fill the buffer pointed to by **pData** with a UINT value that represents the number of [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) surface formats that the device supports. |

See [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) for explanations of other values for **D3DDDIARG_GETCAPS.Type** that are used for multiplane overlays.

### Simple_instancing

If a Direct3D Level 9 driver that supports Windows Display Driver Model (WDDM) 1.3 and later completes a call to **PFND3DDDI_GETCAPS** and returns S_OK but doesn't change the data in the [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure, it is indicating to the Direct3D runtime that the hardware and driver don't support simple instancing. For more info, see [**D3DDDICAPS_SIMPLE_INSTANCING_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_simple_instancing_support).

## See also

[**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**D3DDDICAPS_SIMPLE_INSTANCING_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_simple_instancing_support)

[**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[**D3DDDI_ADAPTERFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adapterfuncs)

[**DDRAW_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddraw_caps)