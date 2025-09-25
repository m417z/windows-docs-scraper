## Description

Sets the base shading rate, and combiners, for variable-rate shading (VRS). For more info, see [Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs).

## Parameters

### `baseShadingRate`

Type: [**D3D12_SHADING_RATE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shading_rate)

A constant from the [D3D12_SHADING_RATE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shading_rate) enumeration describing the base shading rate to set.

### `combiners`

Type: **const [D3D12_SHADING_RATE_COMBINER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shading_rate_combiner)\***

An optional pointer to a constant array of [**D3D12_SHADING_RATE_COMBINER**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shading_rate_combiner) containing the shading rate combiners to set. The count of [**D3D12_SHADING_RATE_COMBINER**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shading_rate_combiner) elements in the array must be equal to the constant [**D3D12_RS_SET_SHADING_RATE_COMBINER_COUNT**](https://learn.microsoft.com/windows/win32/direct3d12/constants), which is equal to **2**.

Because per-primitive and screen-space image-based VRS isn't supported on Tier1 [Variable-rate shading (VRS)](https://learn.microsoft.com/windows/win32/direct3d12/vrs), for these values to be meaningful, the adapter requires Tier2 VRS support. See [**D3D12_FEATURE_DATA_D3D12_OPTIONS6**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options6) and [**D3D12_VARIABLE_SHADING_RATE_TIER**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_variable_shading_rate_tier).

A **NULL** pointer is equivalent to the default shading combiners, which are both [**D3D12_SHADING_RATE_COMBINER_PASSTHROUGH**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shading_rate_combiner).

The algorithm for final shading-rate is determined by the following.

```cpp
postRasterizerRate = ApplyCombiner(Combiners[0], CommandListShadingRate, Primitive->PrimitiveSpecifiedShadingRate);
finalRate = ApplyCombiner(Combiners[1], postRasterizerRate, ScreenSpaceImage[xy]);
```

where `ApplyCombiner` is

```cpp
UINT ApplyCombiner(D3D12_SHADING_RATE_COMBINER combiner, UINT a, UINT b)
{
    MaxShadingRate = options6.AdditionalShadingRatesSupported ? 4 : 2;
    switch (combiner)
    {
        case D3D12_SHADING_RATE_COMBINER_PASSTHROUGH: // default
            return a;
        case D3D12_SHADING_RATE_COMBINER_OVERRIDE:
            return b;
        case D3D12_SHADING_RATE_COMBINER_MAX:
            return max(a, b);
        case D3D12_SHADING_RATE_COMBINER_MIN:
            return min(a, b);
        case D3D12_SHADING_RATE_COMBINER_SUM:
            return min(MaxShadingRate, a + b);
        case default:
            return a;
    }
}
```

## Remarks

## See also

[Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs)