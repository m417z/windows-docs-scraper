# VIDEO_PORT_SERVICES enumeration

## Description

The VIDEO_PORT_SERVICES enumerated type lists the interfaces that the video miniport driver can request from the video port driver by calling [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices).

## Constants

### `VideoPortServicesAGP`

Represents the AGP interface.

### `VideoPortServicesI2C`

Represents the I2C interface.

### `VideoPortServicesHeadless`

Represents the Headless interface.

### `VideoPortServicesInt10`

Represents the Int10 interface.

### `VideoPortServicesDebugReport`

Represents the Debug Report interface, which is available in the following operating systems:

* Windows Server 2003 SP1 and subsequent service packs
* Windows XP SP2 and subsequent service packs

### `VideoPortServicesWCMemoryProtection`

Represents the WC Memory Protection interface.

## Remarks

Many functions are exported by the video port driver; the video miniport driver can call those functions using ordinary dynamic linking. Other functions implemented by the video port driver are not exported; instead, they are made available to the video miniport driver through function pointers. An interface, in this context, is a set of related function pointers. For example, the AGP interface is a set of pointers to functions (implemented by the video port driver) that provide AGP services to the video miniport driver.

The video miniport driver obtains a set of function pointers by passing a value from the VIDEO_PORT_SERVICES enumerated type to the *ServicesType* parameter of the **VideoPortQueryServices** function.

## See also

[AGP Functions Implemented by the Video Port Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/)

[Debug Report Functions Implemented by the Video Port Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[I2C Functions Implemented by the Video Port Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[Int10 Functions Implemented by the Video Port Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices)