# PFND3DDDI_CREATEEXTENSIONDEVICE callback function

## Description

The **CreateExtensionDevice** function creates a DirectX Video Acceleration (DXVA) extension device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [**D3DDDIARG_CREATEEXTENSIONDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createextensiondevice) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information in the structure that the Direct3D runtime can use.

## Return value

**CreateExtensionDevice** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The extension device is successfully created. |
| **E_OUTOFMEMORY** | **CreateExtensionDevice** couldn't allocate the required memory for it to complete. |

## Remarks

For more information, see [Creating and Using a DirectX VA 2.0 Extension Device](https://learn.microsoft.com/windows-hardware/drivers/display/creating-and-using-a-directx-va-2-0-extension-device).

## See also

[**D3DDDIARG_CREATEEXTENSIONDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createextensiondevice)

[**DecodeExtensionExecute**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeextensionexecute)

[**DestroyExtensionDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyextensiondevice)