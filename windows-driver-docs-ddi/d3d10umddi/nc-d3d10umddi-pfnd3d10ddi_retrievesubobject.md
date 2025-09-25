# PFND3D10DDI_RETRIEVESUBOBJECT callback function

## Description

The Direct3D runtime calls the driver's **PFND3D10DDI_RETRIEVESUBOBJECT** function to retrieve subparts of the Direct3D driver device object.

## Parameters

### `unnamedParam1`

*hDevice* [in] A handle to the display device (graphics context).

### `SubDeviceID`

Sub-device ID that identifies the function table being retrieved. See Remarks.

### `ParamSize`

The size, in bytes, of the input parameter structure that **pParams** points to.

### `pParams`

A pointer to an input parameter structure that is described by the **SubDeviceID** parameter. See Remarks.

### `OutputParamSize`

The size, in bytes, of the output parameter structure that **pOutputParamsBuffer** points to.

### `pOutputParamsBuffer`

A pointer to an output parameter structure that is described by the **SubDeviceID** parameter. See Remarks.

## Return value

Returns S_OK if the operation succeeds. Otherwise, this function returns an appropriate error result.

## Remarks

The following table describes the possible values for **SubDeviceID**, the associated input structure pointed to by **pParams**, and the output structure that **PFND3D10DDI_RETRIEVESUBOBJECT** returns in the buffer pointed to by **pOutputParamsBuffer** .

| SubDeviceID | Meaning | pParams | pOutputParamsBuffer |
| ----------- | ------- | ------- | ------------------- |
| 2 | Sub ID for a D3D 11 video function table. | [**D3D11_1DDI_VIDEO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_input) | [**D3D11_1DDI_VIDEODEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_videodevicefuncs) |
| 3 | Sub ID for a WDDM 2.0 video function table. | [**D3DWDDM2_0DDI_VIDEO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_input) | [**D3DWDDM2_0DDI_VIDEODEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_videodevicefuncs) |
| 5 | Sub ID for a WDDM 2.1 video function table. | [**D3DWDDM2_1DDI_VIDEO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_1ddi_video_input) | [**D3DWDDM2_1DDI_VIDEODEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_1ddi_videodevicefuncs) .|
| 6 | Sub ID for a WDDM 2.4 and later video function table. Supported starting with WDDM 2.4. | [**D3DWDDM2_4DDI_VIDEO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_4ddi_video_input) | [**D3DWDDM2_4DDI_VIDEODEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_4ddi_videodevicefuncs). |
| 7 | Sub ID for a WDDM 2.4 (Windows 10 version 1803 release) video function table. | [**D3DWDDM2_4DDI_VIDEO_INPUT_RS4_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_4ddi_video_input_rs4_0) | [**D3DWDDM2_4DDI_VIDEODEVICEFUNCS_RS4_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_4ddi_videodevicefuncs_rs4_0) |

The Direct3D runtime considers the retrieved subparts to be appended to the Direct3D driver device object and expects them to be destroyed along with the rest of the device when [**DestroyDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice) is called.

Subdevices are retrieved from the root device object independently. The DDI interface version is provided implicitly within the sub-device ID.

This function is free-threaded.

## See also

[**DestroyDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice)