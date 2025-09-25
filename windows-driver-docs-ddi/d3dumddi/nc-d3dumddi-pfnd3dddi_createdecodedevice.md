# PFND3DDDI_CREATEDECODEDEVICE callback function

## Description

The **CreateDecodeDevice** function creates a Microsoft DirectX Video Acceleration (DirectX VA) decode device that is used to decode video.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEDECODEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdecodedevice) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information in the structure that the Microsoft Direct3D runtime can use.

## Return value

**CreateDecodeDevice** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The DirectX VA decode device is successfully created. |
| **E_OUTOFMEMORY** | [CreateDecodeDevice]() could not allocate the required memory for it to complete. |

## See also

[D3DDDIARG_CREATEDECODEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdecodedevice)

[DestroyDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydecodedevice)