# IDirectDraw7::WaitForVerticalBlank

## Description

Helps the application synchronize itself with the vertical-blank interval.

## Parameters

### `unnamedParam1` [in]

One of the following flags that indicates how long to wait for the vertical blank:

#### DDWAITVB_BLOCKBEGIN

**WaitForVerticalBlank** returns when the vertical-blank interval begins.

#### DDWAITVB_BLOCKBEGINEVENT

Triggers an event when the vertical blank begins. This value is not currently supported.

#### DDWAITVB_BLOCKEND

**WaitForVerticalBlank** returns when the vertical-blank interval ends and the display begins.

### `unnamedParam2` [in]

Handle of the event to be triggered when the vertical blank begins. This parameter is not currently used.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)