# DDVIDEOPORTDESC structure

## Description

The DDVIDEOPORTDESC structure describes the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object being created.

## Members

### `dwSize`

Specifies the size in bytes of the DDVIDEOPORTDESC structure.

### `dwFieldWidth`

Specifies the width in pixels of the incoming video stream.

### `dwVBIWidth`

Specifies the width, in number of samples, of the [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data in the incoming video stream.

### `dwFieldHeight`

Specifies the field height in scan lines of the incoming video stream.

### `dwMicrosecondsPerField`

Specifies the time interval in microseconds between live video VSYNCs. This number should be rounded up to the nearest whole microsecond.

### `dwMaxPixelsPerSecond`

Specifies the maximum pixel rate per second.

### `dwVideoPortID`

Specifies the ID of the hardware video port to be used. This ID should range from 0 to (**dwMaxVideoPorts** -1), where **dwMaxVideoPorts** is a member of the [DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps) structure.

### `dwReserved1`

Reserved for system use and should be ignored by the driver.

### `VideoPortType`

Specifies a [DDVIDEOPORTCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddvideoportconnect) structure describing the connection characteristics of the hardware video port.

### `dwReserved2`

Reserved for future use and should be ignored by the driver.

### `dwReserved3`

Reserved for future use and should be ignored by the driver.

## See also

[DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps)

[DDVIDEOPORTCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddvideoportconnect)