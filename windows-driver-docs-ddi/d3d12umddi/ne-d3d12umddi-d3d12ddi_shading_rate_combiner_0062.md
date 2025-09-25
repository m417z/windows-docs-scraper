# D3D12DDI_SHADING_RATE_COMBINER_0062 enumeration

## Description

Indicates the type of combiner used to combine two shading rates A and B, where A is the pipeline/render state (per draw) shading rate, and B is one of the following types of shading rates:

* a provoking vertex shading rate (from a vertex shader)
* a per primitive shading rate (from a geometry shader)
* an image based shading rate

## Constants

### `D3D12DDI_SHADING_RATE_COMBINER_0062_PASSTHROUGH`

The default combiner, where the result is A. The pipeline/render state (per draw) shading rate is used.

### `D3D12DDI_SHADING_RATE_COMBINER_0062_OVERRIDE`

The shading rate of type B is used as the shading rate.

### `D3D12DDI_SHADING_RATE_COMBINER_0062_MIN`

The combined shading rate is the minimum of A and B. This shading rate is the higher quality.

### `D3D12DDI_SHADING_RATE_COMBINER_0062_MAX`

The combined shading rate is the maximum of A and B. This shading rate is the lower quality.

### `D3D12DDI_SHADING_RATE_COMBINER_0062_SUM`

Apply the cost of B relative to A. The combined rate is equal to min(*maxRate*, A.xy + B.xy), where *maxRate* is the largest permitted dimension of coarse pixel on the device.

## Remarks

When specifying a shader rate by vertex attribute:

* If a geometry shader is used, the shading rate can be specified through the vertex attribute.

* If a geometry shader is not used, the shading rate is specified by the provoking vertex.

## See also