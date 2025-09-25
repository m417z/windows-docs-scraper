# DD_MOTIONCOMP_LOCAL structure

## Description

The DD_MOTIONCOMP_LOCAL structure contains local data for each individual Microsoft DirectDraw motion compensation object.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current DirectDraw process only.

### `guid`

Specifies a GUID that describes the motion compensation process being used.

### `dwUncompWidth`

Indicates the width in pixels of the uncompressed output frame.

### `dwUncompHeight`

Indicates the height in pixels of the uncompressed output frame.

### `ddUncompPixelFormat`

Specifies a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that contains the pixel format of the uncompressed output frame.

### `dwDriverReserved1`

### `dwDriverReserved2`

### `dwDriverReserved3`

Are reserved for use by the display driver.

### `lpDriverReserved1`

### `lpDriverReserved2`

### `lpDriverReserved3`

Are reserved for use by the display driver.