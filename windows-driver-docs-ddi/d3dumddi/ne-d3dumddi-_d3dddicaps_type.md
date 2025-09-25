# D3DDDICAPS_TYPE enumeration

## Description

A **D3DDDICAPS_TYPE** enumeration value identifies the capability information that is being queried by the D3D runtime in a call to the driver's [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function.

## Constants

### `D3DDDICAPS_DDRAW`

The driver receives a pointer to a [**DDRAW_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddraw_caps) structure.

### `D3DDDICAPS_DDRAW_MODE_SPECIFIC`

The driver receives a pointer to a [**DDRAW_MODE_SPECIFIC_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddraw_mode_specific_caps) structure.

### `D3DDDICAPS_GETFORMATCOUNT`

The driver receives a pointer to the number of surface formats from the [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration type that the device supports. See Remarks.

### `D3DDDICAPS_GETFORMATDATA`

The driver receives a pointer to an array of [**FORMATOP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_formatop) structures for the surface formats that the device supports.

### `D3DDDICAPS_GETMULTISAMPLEQUALITYLEVELS`

The driver receives a pointer to a [**DDIMULTISAMPLEQUALITYLEVELSDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddimultisamplequalitylevelsdata) structure.

### `D3DDDICAPS_GETD3DQUERYCOUNT`

The driver receives a pointer to the number of query types that the driver supports. See Remarks.

### `D3DDDICAPS_GETD3DQUERYDATA`

The driver receives a pointer to an array of structures or data types for different query types, which are represented by values of the D3DDDIQUERYTYPE enumeration type. For more information about D3DDDIQUERYTYPE, see the **QueryType** member of the [**D3DDDIARG_CREATEQUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery) structure.

### `D3DDDICAPS_GETD3D3CAPS`

The driver receives a pointer to a [**D3DHAL_GLOBALDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata) structure.

### `D3DDDICAPS_GETD3D5CAPS`

This value is not used.

### `D3DDDICAPS_GETD3D6CAPS`

This value is not used.

### `D3DDDICAPS_GETD3D7CAPS`

The driver receives a pointer to a [**D3DHAL_D3DEXTENDEDCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_d3dextendedcaps) structure.

### `D3DDDICAPS_GETD3D8CAPS`

The driver receives a pointer to a D3DCAPS8 structure, which is described in the DirectX 8.0 SDK documentation.

### `D3DDDICAPS_GETD3D9CAPS`

The driver receives a pointer to a D3DCAPS9 structure, which is described in the DirectX 9.0 SDK documentation.

### `D3DDDICAPS_GETDECODEGUIDCOUNT`

The driver receives a pointer to the number of DirectX Video Acceleration (DirectX VA) decode types (that is, decode GUIDs) that the driver supports. See Remarks.

### `D3DDDICAPS_GETDECODEGUIDS`

The driver receives a pointer to an array of DirectX VA decode types (that is, decode GUIDs) that the driver supports.

### `D3DDDICAPS_GETDECODERTFORMATCOUNT`

The driver receives a pointer to the number of render target formats for a particular DirectX VA decode type (which is specified by the **pInfo** member of the [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure that the **pData** parameter of the [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function points to). See Remarks.

### `D3DDDICAPS_GETDECODERTFORMATS`

The driver receives a pointer to an array of [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration types that represent the render target formats for a particular DirectX VA decode type (which is specified in a [**DXVADDI_DECODEINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodeinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFOCOUNT`

The driver receives a pointer to the number of types of compressed buffers that are required to accelerate a particular DirectX VA video decode type (which is specified in a [**DXVADDI_DECODEINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodeinput) structure that is pointed to by **pInfo**). See Remarks.

### `D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFO`

The driver receives an array of [**DXVADDI_DECODEBUFFERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodebufferinfo) structures that contain information about the types of compressed buffers that are required to accelerate a particular DirectX VA video decode type (which is specified in a [**DXVADDI_DECODEINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodeinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETDECODECONFIGURATIONCOUNT`

The driver receives a pointer to the number of configurations for a particular render target format of a DirectX VA decode type (which is specified in a [**DXVADDI_DECODEINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodeinput) structure that is pointed to by **pInfo**). See Remarks.

### `D3DDDICAPS_GETDECODECONFIGURATIONS`

The driver receives a pointer to an array of [**DXVADDI_CONFIGPICTUREDECODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_configpicturedecode) structures for the configurations for a particular render target format of a DirectX VA decode type (which is specified in a [**DXVADDI_DECODEINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodeinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETVIDEOPROCESSORDEVICEGUIDCOUNT`

The driver receives a pointer to the number of video processor device types (GUIDs) that are used to process a particular video stream (which is specified in a [**DXVADDI_VIDEODESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure that is pointed to by **pInfo**). See Remarks.

### `D3DDDICAPS_GETVIDEOPROCESSORDEVICEGUIDS`

The driver receives a pointer to an array of video processor device types (GUIDs) that are used to process a particular video stream (which is specified in a [**DXVADDI_VIDEODESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETVIDEOPROCESSORRTFORMATCOUNT`

The driver receives a pointer to the number of render target formats for a particular DirectX VA video processor device type (which is pointed to by the **pVideoProcGuid** member of a [**DXVADDI_VIDEOPROCESSORINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessorinput) structure that is pointed to by **pInfo**). See Remarks.

### `D3DDDICAPS_GETVIDEOPROCESSORRTFORMATS`

The driver receives a pointer to an array of [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration types that represent the render target formats for a particular DirectX VA video processor device type (which is pointed to by the **pVideoProcGuid** member of a [**DXVADDI_VIDEOPROCESSORINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessorinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETVIDEOPROCESSORRTSUBSTREAMFORMATCOUNT`

The driver receives a pointer to the number of render target formats for a particular DirectX VA video processor substream (which is pointed to by the **pVideoProcGuid** member of a [**DXVADDI_VIDEOPROCESSORINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessorinput) structure that is pointed to by **pInfo**). See Remarks.

### `D3DDDICAPS_GETVIDEOPROCESSORRTSUBSTREAMFORMATS`

The driver receives a pointer to an array of [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration types that represent the render target formats for a particular DirectX VA video processor substream (which is pointed to by the **pVideoProcGuid** member of a [**DXVADDI_VIDEOPROCESSORINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessorinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETVIDEOPROCESSORCAPS`

The driver receives a pointer to a [**DXVADDI_VIDEOPROCESSORCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessorcaps) structure that contains information about the video processing capabilities on a particular video stream (which is specified in a [**DXVADDI_VIDEOPROCESSORINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessorinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETPROCAMPRANGE`

The driver receives a pointer to a [**DXVADDI_VALUERANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_valuerange) structure that contains the range of allowed values for a particular ProcAmp control property on a particular video stream (which is specified in a [**DXVADDI_QUERYPROCAMPINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_queryprocampinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_FILTERPROPERTYRANGE`

The driver receives a pointer to a [**DXVADDI_VALUERANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_valuerange) structure that contains the range of allowed values for a particular filter setting on a particular video stream (which is specified in a [**DXVADDI_QUERYFILTERPROPERTYRANGEINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_queryfilterpropertyrangeinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETEXTENSIONGUIDCOUNT`

The driver receives a pointer to the number of extension GUIDs that are supported. See Remarks.

### `D3DDDICAPS_GETEXTENSIONGUIDS`

The driver receives a pointer to an array of extension GUIDs that are supported.

### `D3DDDICAPS_GETEXTENSIONCAPS`

The driver receives a pointer to a private structure that contains information about a capability of an extension GUID (which is specified in a [**DXVADDI_QUERYEXTENSIONCAPSINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_queryextensioncapsinput) structure that is pointed to by **pInfo**).

### `D3DDDICAPS_GETGAMMARAMPCAPS`

The driver receives a pointer to a [**DDIGAMMACAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddigammacaps) structure for the gamma-ramp capabilities that the device supports.

### `D3DDDICAPS_CHECKOVERLAYSUPPORT`

The driver receives a pointer to a D3DOVERLAYCAPS structure that contains information about the capabilities of a particular overlay. The attributes of the overlay and the display mode in which the calling application wants to use the overlay are specified in a [**DDICHECKOVERLAYSUPPORTINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicheckoverlaysupportinput) structure that is pointed to by **pInfo**. If the driver supports the overlay, the driver sets the members of the D3DOVERLAYCAPS; otherwise, the driver fails the call to its [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function with either D3DDDIERR_UNSUPPORTEDOVERLAYFORMAT or D3DDDIERR_UNSUPPORTEDOVERLAY depending on whether the lack of support was based on the overlay format. D3DOVERLAYCAPS is described in the DirectXSDK documentation.

For more information, see [Overlay DDI](https://learn.microsoft.com/windows-hardware/drivers/display/overlay-ddi).

Supported starting with Windows 7.

### `D3DDDICAPS_DXVAHD_GETVPDEVCAPS`

The driver receives a pointer to a [**ns-d3dumddi-_dxvahdddi_vpdevcaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure for the video processor capabilities that the decode device (which is specified in a [**DXVAHDDDI_DEVICE_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_device_desc) structure that is pointed to by **pInfo**) supports.

Supported starting with Windows 7.

### `D3DDDICAPS_DXVAHD_GETVPOUTPUTFORMATS`

The driver receives an array of [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration types that represent the output formats for the decode device (which is specified in a [**DXVAHDDDI_DEVICE_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_device_desc) structure that is pointed to by **pInfo**).

Supported starting with Windows 7.

### `D3DDDICAPS_DXVAHD_GETVPINPUTFORMATS`

The driver receives an array of [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration types that represent the input formats for the decode device (which is specified in a [**DXVAHDDDI_DEVICE_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_device_desc) structure that is pointed to by **pInfo**).

Supported starting with Windows 7.

### `D3DDDICAPS_DXVAHD_GETVPCAPS`

The driver receives an array of [**DXVAHDDDI_VPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps) structures for the capabilities for each video processor that the decode device (which is specified in a [**DXVAHDDDI_DEVICE_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_device_desc) structure that is pointed to by **pInfo**) supports.

Supported starting with Windows 7.

### `D3DDDICAPS_DXVAHD_GETVPCUSTOMRATES`

The driver receives an array of [**DXVAHDDDI_CUSTOM_RATE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_custom_rate_data) structures for the custom frame rates that a video processor (which is specified by a CONST_GUID that is pointed to by **pInfo**) supports.

Supported starting with Windows 7.

### `D3DDDICAPS_DXVAHD_GETVPFILTERRANGE`

The driver receives a pointer to a [**DXVAHDDDI_FILTER_RANGE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_filter_range_data) structure for the range that the filter (which is specified by a [**DXVAHDDDI_FILTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_filter) enumeration value that is pointed to by **pInfo**) supports.

Supported starting with Windows 7.

### `D3DDDICAPS_GETCONTENTPROTECTIONCAPS`

The driver receives a pointer to a D3DCONTENTPROTECTIONCAPS structure for the specific encryption and decode combination (which is specified in a [**DDICONTENTPROTECTIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicontentprotectioncaps) structure that is pointed to by **pInfo**) that the driver should use. D3DCONTENTPROTECTIONCAPS is described in the DirectXSDK documentation.

For more information, see [Content Protection DDI](https://learn.microsoft.com/windows-hardware/drivers/display/content-protection-ddi).

Supported starting with Windows 7.

### `D3DDDICAPS_GETCERTIFICATESIZE`

The driver receives a pointer to a number that specifies the size, in bytes, of the driver's certificate that is used for a channel type. The runtime uses this size to allocate a buffer to hold the certificate. The runtime passes this buffer in the [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) call with D3DDDICAPS_GETCERTIFICATE set.

Supported starting with Windows 7. See Remarks.

### `D3DDDICAPS_GETCERTIFICATE`

The driver receives a pointer to the driver's certificate (which is described in a [**DDICERTIFICATEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicertificateinfo) structure that is pointed to by **pInfo**). The runtime passes a buffer in the **pData** member of the [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure that the driver can fill with the certificate.

Supported starting with Windows 7.

### `D3DDDICAPS_GET_ARCHITECTURE_INFO`

The driver receives a pointer to a [**D3DDDICAPS_ARCHITECTURE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_architecture_info) structure that contains information about the DirectX 11.1 adapter architecture that the device supports.

Supported starting with Windows 8.

### `D3DDDICAPS_GET_SHADER_MIN_PRECISION_SUPPORT`

The driver receives a pointer to a [**D3D11_DDI_SHADER_MIN_PRECISION_SUPPORT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_ddi_shader_min_precision_support_data) structure that specifies the minimum precision levels that the driver supports in shaders.

Supported starting with Windows 8.

### `D3DDDICAPS_GET_MULTIPLANE_OVERLAY_CAPS`

The driver receives a pointer to a [**D3DDDI_MULTIPLANE_OVERLAY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_caps) structure that specifies basic multiplane overlay capabilities. In this case, the members of the [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure indicate the following:

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**Type** has a value of **D3DDDICAPS_GET_MULTIPLANE_OVERLAY_CAPS**.If the [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with this value for **Type** and the driver does not support multiplane overlays, the driver should return an error code.

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**pInfo** is a pointer of type **D3DDDI_VIDEO_PRESENT_SOURCE_ID** to the zero-based identification number of the video present source, **VidPnSourceId**.

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**pData** is a pointer of type [**D3DDDI_MULTIPLANE_OVERLAY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_caps) to the capabilities structure that the driver fills out.

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**DataSize** is the value of ```sizeof(D3DDDI_MULTIPLANE_OVERLAY_CAPS)```.

Supported starting with Windows 8.1.

### `D3DDDICAPS_GET_MULTIPLANE_OVERLAY_FILTER_RANGE`

Reserved for system use. Do not use in your driver.

Supported starting with Windows 8.

### `D3DDDICAPS_GET_MULTIPLANE_OVERLAY_GROUP_CAPS`

The driver receives a pointer to a [**D3DDDI_MULTIPLANE_OVERLAY_GROUP_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_group_caps) structure that specifies a group of overlay plane capabilities. In this case, the members of the [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure indicate the following:

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**Type** has a value of **D3DDDICAPS_GET_MULTIPLANE_OVERLAY_GROUP_CAPS**.If the [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with this value for **Type** and the driver does not support multiplane overlays, the driver should return an error code.

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**pInfo** is a pointer of type [**D3DDDI_MULTIPLANE_OVERLAY_GROUP_CAPS_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_group_caps_input) to the zero-based identification number of the video present source, **VidPnSourceId**, and to the capability group index, **GroupIndex**.

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**pData** is a pointer of type [**D3DDDI_MULTIPLANE_OVERLAY_GROUP_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_group_caps) to the capabilities structure that the driver fills out.

* [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).**DataSize** is the value of ```sizeof(D3DDDI_MULTIPLANE_OVERLAY_GROUP_CAPS)```.

Supported starting with Windows 8.1.

### `D3DDDICAPS_GET_SIMPLE_INSTANCING_SUPPORT`

The driver receives a pointer to a [**D3DDDICAPS_SIMPLE_INSTANCING_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_simple_instancing_support) structure that specifies simple instancing capabilities.

Supported starting with Windows 8.1.

### `D3DDDICAPS_GET_MARKER_CAPS`

Supported starting with Windows 8.1.

## Remarks

For information on how to specify [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) member values along with **D3DDDICAPS_TYPE** constant values, see Remarks of [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps).

## See also

[**D3D11_DDI_SHADER_MIN_PRECISION_SUPPORT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_ddi_shader_min_precision_support_data)

[**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**D3DDDICAPS_ARCHITECTURE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_architecture_info)

[**D3DDDICAPS_SIMPLE_INSTANCING_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_simple_instancing_support)

[**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[**D3DDDI_MULTIPLANE_OVERLAY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_caps)

[**D3DDDI_MULTIPLANE_OVERLAY_GROUP_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_group_caps)

[**D3DDDI_MULTIPLANE_OVERLAY_GROUP_CAPS_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_group_caps_input)

[**DDICERTIFICATEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicertificateinfo)

[**DDICHECKOVERLAYSUPPORTINPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicheckoverlaysupportinput)

[**DDICONTENTPROTECTIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicontentprotectioncaps)

[**DDRAW_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddraw_caps)

[**DDRAW_MODE_SPECIFIC_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddraw_mode_specific_caps)

[**DXVAHDDDI_CUSTOM_RATE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_custom_rate_data)

[**DXVAHDDDI_DEVICE_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_device_desc)

[**DXVAHDDDI_FILTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_filter)

[**DXVAHDDDI_FILTER_RANGE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_filter_range_data)

[**DXVAHDDDI_VPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps)

[**ns-d3dumddi-_dxvahdddi_vpdevcaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[**FORMATOP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_formatop)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)