# _D3DDDIARG_SETPRIORITY structure

## Description

The D3DDDIARG_SETPRIORITY structure describes the priority level to set for a managed texture.

## Members

### `hResource`

A handle to the resource that contains the texture.

### `Priority`

The priority level to set for the texture that is contained in the **hResource** resource. A texture's priority value can be set anywhere in the range from 0 through 0xFFFFFFFF.

## Remarks

The driver receives only priority notifications for driver-managed textures.

The priority level at which a texture is set determines its eviction order from memory. A texture that is assigned a low priority is evicted before a texture with a high priority. If two textures have the same priority, the texture that was used more recently is kept in memory; the other texture is evicted.

## See also

[SetPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpriority)