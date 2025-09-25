# VideoPortIsNoVesa function

## Description

The **VideoPortIsNoVesa** function determines whether a video miniport driver that does not support Plug and Play (PnP) is restricted to legacy VGA resources.

## Return value

If **VideoPortIsNoVesa** returns **TRUE**, then a non-PnP video miniport driver must restrict its hardware access to legacy VGA resources. Otherwise, the video miniport driver is permitted to use non-legacy VGA resources.

## Remarks

This function is useful only to vga.sys, which is a system-supplied video miniport driver that does not support PnP. This function provides no pertinent information to video miniport drivers that support PnP and therefore is no use to IHVs.

If **VideoPortIsNoVesa** returns **TRUE**, then the video miniport driver must access the display adapter only through legacy VGA resources (I/O 3B0 through 3DF; memory A0000 through BFFFF). Specifically, if **VideoPortIsNoVesa** returns **TRUE**, the video miniport driver must not attempt to call the Int10 functions, which are implemented by the video port driver.

For more information about the Int10 functions, see [Int10 Functions Implemented by the Video Port Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/).