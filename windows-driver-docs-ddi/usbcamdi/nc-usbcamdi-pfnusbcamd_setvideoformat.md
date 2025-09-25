## Description

The **USBCAMD_SetVideoFormat** service is used to notify USBCAMD that the video format has changed.

## Parameters

### `DeviceContext` [in]

Pointer to device-specific context.

### `pSrb` [in]

Pointer to a stream request block (SRB).

## Return value

**USBCAMD_SetVideoFormat** returns **TRUE** if the call was successful, otherwise it returns **FALSE** and sets *pSrb->Status* to one of the following error codes:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | USBCAMD may return STATUS_INVALID_PARAMETER for a number of reasons, including: Unknown video format Arithmetic overflow when calculating the video info header size or format size. |
| **STATUS_INSUFFICIENT_RESOURCES** | There are insufficient resources to allocate the video info header. |

## Remarks

Note that this function returns **TRUE** to indicate success and not STATUS_SUCCESS.

Camera minidrivers must handle all SRBs related to video format. Camera minidrivers should use **USBCAMD_SetVideoFormat** to inform USBCAMD of a video format change. Typically, the camera minidriver calls **USBCAMD_SetVideoFormat** from within its SRB_SET_DATA_FORMAT handler.

**USBCAMD_SetVideoFormat** is not available in USBCAMD version 1.0.

## See also

[SRB_SET_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-data-format)

[**USBCAMD_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-usbcamd_interface)