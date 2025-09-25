# IPortableDeviceServiceCapabilities::GetFormatRenderingProfiles

## Description

The **GetFormatRenderingProfiles** method retrieves the rendering profiles of a format.

## Parameters

### `Format` [in]

The format whose rendering profiles are retrieved.

### `ppRenderingProfiles` [out]

The [IPortableDeviceValuesCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevaluescollection) object that receives the list of rendering profiles.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

The rendering profiles are similar to what the [WPD_FUNCTIONAL_CATEGORY_RENDERING_INFORMATION](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-functional-category-rendering-information) functional object returns for device-wide rendering profiles, so that the **DisplayRenderingProfile** helper function described in [Retrieving the Rendering Capabilities Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-rendering-capabilities-supported-by-a-device) could be used here as well. But there are differences: The **GetFormatRenderingProfiles** method retrieves only rendering profiles that apply to the selected service and have been filtered by format.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)