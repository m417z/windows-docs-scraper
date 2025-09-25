# _D3DHAL_DP2SETPRIORITY structure

## Description

The D3DHAL_DP2SETPRIORITY structure is used to inform the driver of the priority of the texture specified by the handle **dwDDDestSurface**.

## Members

### `dwDDSurface`

Specifies the handle of the texture.

### `dwPriority`

Specifies the priority of the **dwDDDestSurface** texture. A texture's priority value can be set anywhere in the range from 0 to 0xFFFFFFFF.

## Remarks

Drivers are notified of handles at texture creation time. The driver can expect to receive priority notifications only for driver-managed textures.

Priorities determine when managed textures are to be evicted from memory. A texture assigned a low priority is evicted before a texture with a high priority. If two textures have the same priority, the texture that was used more recently is kept in memory; the other texture is evicted.