## Description

The **DdControlColor** callback function controls the luminance and brightness controls of an overlay surface.

## Parameters

### `unnamedParam1`

Points to a [DD_COLORCONTROLDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontroldata) structure that contains the color control information for a specified overlay surface.

## Return value

**DdControlColor** returns a callback code.

## Remarks

**DdControlColor** can be optionally implemented in a DirectDraw driver.

## See also

[DD_COLORCONTROLDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontroldata)