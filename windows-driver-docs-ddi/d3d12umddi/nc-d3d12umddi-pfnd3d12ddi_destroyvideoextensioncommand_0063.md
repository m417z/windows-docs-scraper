# PFND3D12DDI_DESTROYVIDEOEXTENSIONCOMMAND_0063 callback function

## Description

Destroys the video extension command.

## Parameters

### `hDrvDevice`

Handle for the Direct3D 12 device.

### `hDrvVideoExtensionCommand`

Handle to the D3D12DDI_HVIDEOEXTENSIONCOMMAND_0063 to be destroyed.

## Prototype

```
//Declaration

PFND3D12DDI_DESTROYVIDEOEXTENSIONCOMMAND_0063 Pfnd3d12ddiDestroyvideoextensioncommand0063;

// Definition

VOID Pfnd3d12ddiDestroyvideoextensioncommand0063
(
	D3D12DDI_HDEVICE hDrvDevice
	D3D12DDI_HVIDEOEXTENSIONCOMMAND_0063 hDrvVideoExtensionCommand
)
{...}

```

## Remarks

## See also