# D3D12EnableExperimentalFeatures function

## Description

Enables a list of experimental features.

## Parameters

### `NumFeatures`

Type: **UINT**

The number of experimental features to enable.

### `pIIDs` [in]

Type: **const IID***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `__in_ecount(NumFeatures)`

A pointer to an array of IDs that specify which of the available experimental features to enable.

### `pConfigurationStructs` [in]

Type: **void***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `__in_ecount(NumFeatures)`

Structures that contain additional configuration details that some experimental features might need to be enabled.

### `pConfigurationStructSizes` [in]

Type: **UINT***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `__in_ecount(NumFeatures)`

The sizes of any configuration structs passed in pConfigurationStructs parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code that can include E_NOINTERFACE if an unrecognized feature is specified or Developer Mode is not enabled, or E_INVALIDARG if the configuration of a feature is in correct, the experimental features specified are not compatible, or other errors.

## Remarks

Call this function before device creation.

Because the set of experimental features will change over time, and because these features may not be stable, they are intended for development and experimentation only. This is enforced by requiring Developer Mode to be active before any experimental features can be enabled.

The set of experimental features that are currently supported can be found in the D3D12.h header, near the definition of the D3D12EnableExperimentalFeatures function; because experimental features are only made available infrequently, its typical to find that no experimental features are currently supported.

Some experimental features might be identified by using an IID as the GUID. For these features, you can use D3D12GetDebugInterface, passing an IID as a parameter, to retrieve the interface for manipulating that feature.

If this function is called again with a different list of features to enable, all current D3D12 devices are set to the DEVICE_REMOVED state.

#### Examples

This example shows what an experimental feature definition looks like.

```cpp
// --------------------------------------------------------------------------------------------------------------------------------
// Experimental Feature: D3D12ExperimentalShaderModels
//
// Use with D3D12EnableExperimentalFeatures to enable experimental shader model support,
// meaning shader models that haven't been finalized for use in retail.
//
// Enabling D3D12ExperimentalShaderModels needs no configuration struct, pass NULL in the pConfigurationStructs array.
//
// --------------------------------------------------------------------------------------------------------------------------------
static const UUID D3D12ExperimentalShaderModels = { /* 76f5573e-f13a-40f5-b297-81ce9e18933f */
    0x76f5573e,
    0xf13a,
    0x40f5,
    { 0xb2, 0x97, 0x81, 0xce, 0x9e, 0x18, 0x93, 0x3f }
};
	
```

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-functions)