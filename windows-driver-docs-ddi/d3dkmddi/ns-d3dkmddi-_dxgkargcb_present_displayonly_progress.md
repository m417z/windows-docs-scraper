# DXGKARGCB_PRESENT_DISPLAYONLY_PROGRESS structure

## Description

The **DXGKARGCB_PRESENT_DISPLAYONLY_PROGRESS** structure provides the progress of a kernel-mode display-only driver's (KMDOD) present operation that was requested by the operating system.

## Members

### `VidPnSourceId`

An integer that identifies a video present source.

### `ProgressId`

A value of type [**DXGK_PRESENT_DISPLAY_ONLY_PROGRESS_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_present_display_only_progress_id) that represents the status of the current present operation.

## See also

[**DXGK_PRESENT_DISPLAY_ONLY_PROGRESS_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_present_display_only_progress_id)

[**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)