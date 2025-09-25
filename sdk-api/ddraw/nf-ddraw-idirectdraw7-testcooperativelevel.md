# IDirectDraw7::TestCooperativeLevel

## Description

Reports the current cooperative-level status of the DirectDraw device for a windowed or full-screen application.

## Return value

If the method succeeds, the return value is DD_OK, which indicates that the calling application can continue.

If it fails, the method can return one of the following error values (see Remarks):

* DDERR_INVALIDOBJECT
* DDERR_EXCLUSIVEMODEALREADYSET
* DDERR_NOEXCLUSIVEMODE
* DDERR_WRONGMODE

## Remarks

This method is particularly useful to applications that use the WM_ACTIVATEAPP and WM_DISPLAYCHANGE system messages as a notification to restore surfaces or recreate DirectDraw objects. The DD_OK return value always indicates that the application can continue, but the error codes are interpreted differently, depending on the cooperative level that the application uses.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)