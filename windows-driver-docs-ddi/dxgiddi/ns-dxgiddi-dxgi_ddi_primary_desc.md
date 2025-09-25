# DXGI_DDI_PRIMARY_DESC structure

## Description

Describes a resource that is used as a primary (that is, a resource that is scanned out to the display).

## Members

### `Flags` [in]

A valid bitwise OR of any of the following values that indicates how the resource is displayed.

| **Value** | **Meaning** |
|:--|:--|
| DXGI_DDI_PRIMARY_OPTIONAL (0x1) | The user-mode display driver can prevent the resource from ever being a primary.<br>The driver can prevent the actual flip (from optional primary to regular primary) and can use a copy-style present operation. Therefore, in this way, the driver might be able to prevent the resource from being actually used as a primary. |
| DXGI_DDI_PRIMARY_NONPREROTATED (0x2) | The primary really represents the DXGI_DDI_MODE_ROTATION_IDENTITY-type rotation, even though it is used with non-DXGI_DDI_MODE_ROTATION_IDENTITY-type display modes, because applications will handle the output orientation by rotating, for example, the viewport and projection matrix. |
| DXGI_DDI_PRIMARY_STEREO (0x4) | Supported in Windows 8 and later versions.<br>The primary represents a stereo back buffer. |
| DXGI_DDI_PRIMARY_INDIRECT (0x8) | Supported in Windows 10 and later versions.<br>The primary will be used for presenting to an indirect display device. |

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the primary surface is created on.

### `ModeDesc` [in]

A [DXGI_DDI_MODE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_mode_desc) structure that describes the display mode.

### `DriverFlags` [out]

A valid bitwise OR of values that indicate how the driver can display the resource.

The DXGI_DDI_PRIMARY_DRIVER_FLAG_NO_SCANOUT (0x1) value is currently the only supported value. This bit indicates that the driver cannot support the runtime setting any subresource of the specified resource as a primary. The user-mode display driver should set this bit if it implements presentation from this surface through a copy operation. Therefore, the runtime will not use flip-style presentation if this bit is set.

## See also

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[DXGI_DDI_MODE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_mode_desc)