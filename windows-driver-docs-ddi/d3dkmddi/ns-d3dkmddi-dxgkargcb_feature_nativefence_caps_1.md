## Description

The **DXGKARGCB_FEATURE_NATIVEFENCE_CAPS_1** structure describes the native fence capabilities of the OS.

## Members

### `SupportOptimizedDefaultFenceType`

Indicates whether the OS supports **D3DDDI_NATIVEFENCE_TYPE_DEFAULT** as described in [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects). If the OS sets this as TRUE, the OS supports allocating native fence storage in VRAM. KMD should query this OS cap and determine whether the OS allows KMD to specify a local memory **SupportedSegmentSet** during the creation of fence type **D3DDDI_NATIVEFENCE_TYPE_DEFAULT**.

### `SupportIntraGpuFenceType`

Indicates whether the OS supports **D3DDDI_NATIVEFENCE_TYPE_INTRA_GPU** as described in [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## Remarks

For a sample code snippet and more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKCB_FEATURE_NATIVEFENCE_CAPS_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_feature_nativefence_caps_1)