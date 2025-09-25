# PFND3DDDI_CREATEVIDEOPROCESSDEVICE callback function

## Description

The **CreateVideoProcessDevice** function creates a Microsoft DirectX Video Acceleration (DirectX VA) video processing device that is used to process video (for example, to deinterlace the video and adjust ProcAmp properties of the video).

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEVIDEOPROCESSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createvideoprocessdevice) structure. On input, contains information that the driver can use. On output, the driver specifies information that the Microsoft Direct3D runtime can use.

## Return value

**CreateVideoProcessDevice** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The video processing device is successfully created. |
| **E_OUTOFMEMORY** | [CreateVideoProcessDevice]() could not allocate the required memory for it to complete. |

## See also

[D3DDDIARG_CREATEVIDEOPROCESSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createvideoprocessdevice)

[DestroyVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyvideoprocessdevice)