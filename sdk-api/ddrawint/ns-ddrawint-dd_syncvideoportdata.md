# DD_SYNCVIDEOPORTDATA structure

## Description

The DD_SYNCVIDEOPORTDATA structure contains the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that describes the hardware video port with which to sync.

### `dwOriginOffset`

Contains the byte offset from the top left corner of the surface to the top left corner of where the VPE object writes its data. This value is only used by the video miniport driver. This member must contain data that is filled in by the driver.

### `dwHeight`

Contains the height in pixels of the VPE object data. By default, this is twice the field height when interleaved, but the driver can change this if it needs to. This value is used only by the video miniport driver. This member can be modified by the driver, but does not need to be.

### `dwVBIHeight`

Contains the number of lines in the [VBI](https://learn.microsoft.com/windows-hardware/drivers/) region. This value is used only by the video miniport driver. This member can be modified by the driver, but does not need to be.

### `dwDriverReserved1`

Is reserved for use by the display driver.

### `dwDriverReserved2`

Reserved for use by the display driver.

### `dwDriverReserved3`

Reserved for use by the display driver.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdSyncVideoPortData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncvideoport) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdSyncVideoPortData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncvideoport)