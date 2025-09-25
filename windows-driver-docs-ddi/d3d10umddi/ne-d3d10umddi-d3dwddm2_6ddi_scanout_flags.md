# D3DWDDM2_6DDI_SCANOUT_FLAGS enumeration

## Description

Used in the [PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_query_scanout_caps) callback to indicate the transformation requirement in preparation for a flip operation.

## Constants

### `D3DWDDM2_6DDI_SCANOUT_FLAG_NONE`

A transformation requirement is not defined.

### `D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_REQUIRED`

A transformation is required. If transformation is required, the runtime will call [PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_prepare_scanout_transformation).

### `D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_DESIRED`

A transformation should occur. If there has been no API request to disable the transformation, then the runtime will call [PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_prepare_scanout_transformation).

### `D3DWDDM2_6DDI_SCANOUT_FLAG_UNPREDICTABLE_TIMING`

Indicates to the runtime whether the resulting allocation follows a predictable scanout timing or not. This information will be used to adjust the front-buffer rendering safety margins.

## Remarks

The driver may not set both the D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_REQUIRED and D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_DESIRED flag.

## See also

[PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_prepare_scanout_transformation)

[PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_query_scanout_caps)