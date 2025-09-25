# _DXVAHDDDI_STREAM_STATE_PALETTE_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_PALETTE_DATA structure describes stream-state data that specifies the palette entries of the input.

## Members

### `Count` [in]

The number of palette entries in the array that the **pEntries** member specifies. The default value is 0.

### `pEntries` [in]

An array of palette entries in either D3DFMT_A8R8G8B8 or "AYUV" [FOURCC](https://learn.microsoft.com/windows-hardware/drivers/) format type. **pEntries** is set to **NULL** to retrieve the number of palette entries. The default value is **NULL**.

## Remarks

The 4-bit palletized "AYUV" FOURCC formats, "AI44", and "IA44" uses the first 16 entries.

The 8-bit palletized "AYUV" FOURCC format, "AI88", D3DFMT_A8P8, and D3DFMT_P8 formats uses the first 256 entries.

If a pixel has a palette index greater than the entries, the driver assumes that the palette entry is white with opaque alpha. Full range RGB is D3DCOLOR_ARGB(255, 255, 255, 255), and YCbCr is D3DCOLOR_AYUV(255, 235, 128, 128).

The Direct3D runtime maintains all the palette entries. However, the driver might truncate the palette entries array to the maximum entries required for the supported palletized format.

The alpha value of each entry is used for the alpha blending.

If the driver does not set the DXVAHDDDI_FEATURE_CAPS_ALPHA_PALETTE value in the **FeatureCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set, every palette entry must have the alpha value set to opaque (0xFF); otherwise, the driver's [SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate) function returns an error.

For more information about alpha blending, see [DXVAHDDDI_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_alpha_data).

## See also

[DXVAHDDDI_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_alpha_data)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)

[SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate)