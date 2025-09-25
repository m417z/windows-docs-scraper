# _DXVA_ProcAmpControlCaps structure

## Description

The DXVA_ProcAmpControlCaps structure identifies the ProcAmp operations that the hardware supports.

## Members

### `Size`

Specifies the size of this structure in bytes.

### `InputPool`

Indicates the memory pool from which the ProcAmp control source surfaces should be allocated. For more information, see the D3DPOOL enumeration in the Microsoft Window SDK documentation.

### `d3dOutputFormat`

Indicates the Direct3D surface format of the output frames. Usually the ProcAmp device outputs frames in a surface format that matches the input surface format. This member ensures that the [VMR](https://learn.microsoft.com/windows-hardware/drivers/) or other video renderer is able to supply the correct format for the output frame surfaces to the ProcAmp control hardware. If the **DXVA_VideoProcess_YUV2RGB** flag is returned in the [DXVA_VideoProcessCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videoprocesscaps) structure, the VMR assumes that valid output formats are specified by this member as well as the RGB32 format.

### `ProcAmpControlProps`

Identifies the ProcAmp operations that the hardware supports. The driver should return a logical combination of the following ProcAmp operations.

|Value|Description|
|--- |--- |
|DXVA_ProcAmp_None|No operations are allowed.|
|DXVA_ProcAmp_Brightness|Brightness adjustments to the video image are allowed.|
|DXVA_ProcAmp_Contrast|Contrast adjustments to the video image are allowed.|
|DXVA_ProcAmp_Hue|Hue adjustments to the video image are allowed.|
|DXVA_ProcAmp_Saturation|Saturation adjustments to the video image are allowed.|

### `VideoProcessingCaps`

Identifies the operations that can be performed by the ProcAmp control hardware concurrently with the requested ProcAmp adjustment. The driver should return a logical combination of one of the following ProcAmp operations.

|Value|Description|
|--- |--- |
|DXVA_VideoProcess_None|No operations are allowed.|
|DXVA_VideoProcess_YUV2RGB|Video conversion from the YUV color space to the RGB color space is allowed. The RGB format used will have at least 8 bits of precision for each color component. If this is possible, a buffer copy within the VMR can be avoided. Note that there is no requirement to convert from the RGB color space to the YUV color space.|
|DXVA_VideoProcess_StretchX|Aspect ratio correction can be performed at the same time as the video is being ProcAmp-adjusted if the hardware is able to stretch or shrink horizontally.|
|DXVA_VideoProcess_StretchY|Aspect ratio adjustment is combined with a general picture resizing operation to scale the video image within an application-defined composition space. This is rare and not an essential feature. It is best if the scaling needed for resizing the video to fit into the application window can be done at the same time as the scaling needed for ProcAmp adjustment. This avoids cumulative artifacts.|
|DXVA_VideoProcess_AlphaBlend|Indicates that the VMR will not perform a buffer copy when an alpha value is changed. It is rare that applications alter the constant alpha value associated with the video stream, so this is a low priority feature.|

## See also

[DXVA_ProcAmpControlProp](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_procampcontrolprop)

[DXVA_VideoProcessCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videoprocesscaps)