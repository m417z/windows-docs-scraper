## Description

The **DXGKCBINT_FEATURE_NATIVEFENCE_1** structure is an internal driver structure used by KMD to query the OS for its support of native GPU fence features.

## Members

### `GetOSCaps`

[in/out] The OS's [**DXGKCB_FEATURE_NATIVEFENCE_CAPS_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_feature_nativefence_caps_1) callback function from which the OS returns its support for native GPU fence features.

## Remarks

KMD queries the OS's native GPU fence features by calling the callback function that **GetOSCaps** points to. KMD should maintain an internal cache for the state and version of the results returned.

For a sample code snippet and more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKCB_FEATURE_NATIVEFENCE_CAPS_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_feature_nativefence_caps_1)

[isfeatureenabled]()