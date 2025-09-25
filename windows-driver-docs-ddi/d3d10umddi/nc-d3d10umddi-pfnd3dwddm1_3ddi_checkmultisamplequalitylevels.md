# PFND3DWDDM1_3DDI_CHECKMULTISAMPLEQUALITYLEVELS callback function

## Description

 **PFND3DWDDM1_3DDI_CHECKMULTISAMPLEQUALITYLEVELS** retrieves the number of quality levels that the device supports for the specified number of samples.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `Format`

A value of type [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) that indicates the render-target format that the check is performed for.

### `SampleCount`

The number of samples to retrieve the quality levels for.

### `Flags`

A combination of [**D3DWDDM1_3DDI_CHECK_MULTISAMPLE_QUALITY_LEVELS_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_check_multisample_quality_levels_flag) values that are combined by using a bitwise OR operation.

### `pNumQualityLevels`

A pointer to a variable that receives the number of quality levels that the device supports for the specified number of samples.

## Remarks

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code. The driver can set **E_INVALIDARG** if the format in the **Format** parameter does not exist or the **pNumQualityLevels** parameter is NULL.

If the device does not support multiple sampling with the number of samples that is specified in the **SampleCount** parameter, the user-mode display driver should return zero in the variable that the **pNumQualityLevels** parameter points to.

When the driver returns 1 or more in the variable that **pNumQualityLevels** points to, the driver indicates the number of device-specific sampling variations that are available with the given sample count. For example, if the driver returns 3, quality levels 0, 1, and 2 can be used to create resources with the given sample count. The device manufacturer defines these quality levels, which the Microsoft Direct3D runtime cannot query. However, different quality levels at a fixed sample count might refer to different spatial layouts of the sample locations or different methods of resolving.

If the driver receives 1 in **SampleCount**, the driver always returns 1 in the variable that **pNumQualityLevels** points to.

If the driver receives 0 or greater than 32 in **SampleCount**, the driver always returns 0 in the variable that **pNumQualityLevels** points to.

## See also

[**CheckMultisampleQualityLevels**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkmultisamplequalitylevels)

[**D3DWDDM1_3DDI_CHECK_MULTISAMPLE_QUALITY_LEVELS_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_check_multisample_quality_levels_flag)

[**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)

[**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)