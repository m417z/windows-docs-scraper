## Description

The **DdMoCompGetFormats** callback function indicates the uncompressed formats to which the hardware can decode the data.

## Parameters

### `unnamedParam1`

Points to a [DD_GETMOCOMPFORMATSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getmocompformatsdata) structure that contains the uncompressed format information for the hardware.

## Return value

**DdMoCompGetFormats** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support motion compensation must implement **DdMoCompGetFormats**.

## See also

[DD_GETMOCOMPFORMATSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getmocompformatsdata)