# DDHAL_WAITFORVERTICALBLANKDATA structure

## Description

The DD_WAITFORVERTICALBLANKDATA structure contains information necessary to obtain the monitor's vertical blank information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `dwFlags`

Specifies how the driver should wait for the vertical blank. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDWAITVB_BLOCKBEGIN | The driver should return when it detects the beginning of the vertical blank interval. |
| DDWAITVB_BLOCKBEGINEVENT | Set up an event to trigger when the vertical blank begins. This flag is not currently supported. |
| DDWAITVB_BLOCKEND | The driver should return when it detects the end of the vertical blank interval and display begins. |
| DDWAITVB_I_TESTVB | The driver should determine whether a vertical blank is currently occurring and return the status in **bIsInVB**. |

### `bIsInVB`

Indicates the status of the vertical blank. A value of **TRUE** indicates that the device is in a vertical blank; **FALSE** means that it is not. The driver should return the current vertical blanking status in this member when **dwFlags** is DDWAITVB_I_TESTVB.

### `hEvent`

Handle for the event that should be triggered when the vertical blank begins. The event is triggered on an interrupt, so if your hardware is able to generate an interrupt on the vertical blank, you should pass this event handle to your [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/video/nc-video-pvideo_hw_interrupt) function so that the event is triggered when the interrupt fires. This member is currently unsupported and should be ignored by the driver.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdWaitForVerticalBlank](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_waitforverticalblank) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `WaitForVerticalBlank`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdWaitForVerticalBlank](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_waitforverticalblank)