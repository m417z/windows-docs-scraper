# DD_VIDEOPORTCALLBACKS structure

## Description

The DD_VIDEOPORTCALLBACKS structure contains entry pointers to Microsoft DirectDraw [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) callback functions that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this DD_VIDEOPORTCALLBACKS structure.

### `dwFlags`

Indicates what VPE callback functions the driver has implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_VPORT32_CANCREATEVIDEOPORT

DDHAL_VPORT32_CREATEVIDEOPORT

DDHAL_VPORT32_FLIP

DDHAL_VPORT32_GETBANDWIDTH

DDHAL_VPORT32_GETINPUTFORMATS

DDHAL_VPORT32_GETOUTPUTFORMATS

DDHAL_VPORT32_GETAUTOFLIPSURF

DDHAL_VPORT32_GETFIELD

DDHAL_VPORT32_GETLINE

DDHAL_VPORT32_GETCONNECT

DDHAL_VPORT32_DESTROY

DDHAL_VPORT32_GETFLIPSTATUS

DDHAL_VPORT32_UPDATE

DDHAL_VPORT32_WAITFORSYNC

DDHAL_VPORT32_GETSIGNALSTATUS

DDHAL_VPORT32_COLORCONTROL

### `CanCreateVideoPort`

Points to the driver-supplied [DdVideoPortCanCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_cancreatevideoport) callback.

### `CreateVideoPort`

Points to the driver-supplied [DdVideoPortCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_createvideoport) callback.

### `FlipVideoPort`

Points to the driver-supplied [DdVideoPortFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_flip) callback.

### `GetVideoPortBandwidth`

Points to the driver-supplied [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth) callback.

### `GetVideoPortInputFormats`

Points to the driver-supplied [DdVideoPortGetInputFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getinputformats) callback.

### `GetVideoPortOutputFormats`

Points to the driver-supplied [DdVideoPortGetOutputFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getoutputformats) callback.

### `lpReserved1`

Reserved for system use and should be ignored by the driver.

### `GetVideoPortField`

Points to the driver-supplied [DdVideoPortGetField](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getfield) callback.

### `GetVideoPortLine`

Points to the driver-supplied [DdVideoPortGetLine](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getline) callback.

### `GetVideoPortConnectInfo`

Points to the driver-supplied [DdVideoPortGetConnectInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getvportconnect) callback.

### `DestroyVideoPort`

Points to the driver-supplied [DdVideoPortDestroy](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_destroyvport) callback.

### `GetVideoPortFlipStatus`

Points to the driver-supplied [DdVideoPortGetFlipStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getflipstatus) callback.

### `UpdateVideoPort`

Points to the driver-supplied [DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update) callback.

### `WaitForVideoPortSync`

Points to the driver-supplied [DdVideoPortWaitForSync](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_waitforsync) callback.

### `GetVideoSignalStatus`

Points to the driver-supplied [DdVideoPortGetSignalStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getsignalstatus) callback.

### `ColorControl`

Points to the driver-supplied [DdVideoPortColorControl](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_colorcontrol) callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver should initialize this structure when its [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function is called with the GUID_VideoPortCallbacks GUID.

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)