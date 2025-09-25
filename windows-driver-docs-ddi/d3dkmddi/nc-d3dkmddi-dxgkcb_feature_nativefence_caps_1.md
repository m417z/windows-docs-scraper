## Description

**DXGKCB_FEATURE_NATIVEFENCE_CAPS_1** is the OS's interface table dedicated to version 1 of [**DXGK_FEATURE_NATIVE_FENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id).

## Parameters

### `pArgs`

[in/out] Pointer to a [**DXGKARGCB_FEATURE_NATIVEFENCE_CAPS_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_feature_nativefence_caps_1) structure in which the OS returns the support it's providing.

## Return value

**DXGKCB_FEATURE_NATIVEFENCE_CAPS_1** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

 KMD calls **DXGKCB_FEATURE_NATIVEFENCE_CAPS_1** to determine the OS's support for the native GPU fence feature.

For a sample code snippet and more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARGCB_FEATURE_NATIVEFENCE_CAPS_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_feature_nativefence_caps_1)

[**DXGKCBINT_FEATURE_NATIVEFENCE_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkcbint_feature_nativefence_1)