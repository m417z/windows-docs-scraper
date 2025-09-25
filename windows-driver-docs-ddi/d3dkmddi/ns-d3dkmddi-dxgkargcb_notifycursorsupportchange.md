## Description

The **DXGKARGCB_NOTIFYCURSORSUPPORTCHANGE** structure contains arguments for the [**DXGKCB_NOTIFYCURSORSUPPORTCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notifycursorsupportchange) callback function.

## Members

### `DeviceHandle` [in]

A handle to the adapter object for the GPU. The driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `VidPnSourceId` [in]

The [ID of the video present source](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_source) on which cursor support is being changed. The OS fails the [**DXGKCB_NOTIFYCURSORSUPPORTCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notifycursorsupportchange) callback if **VidPnSourceId** isn't valid.

## See also

[**DXGKCB_NOTIFYCURSORSUPPORTCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notifycursorsupportchange)