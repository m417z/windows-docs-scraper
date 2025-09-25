# IDirectManipulationManager::Activate

## Description

Activates [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) for processing input and handling callbacks on the specified window.

## Parameters

### `window` [in]

The window in which to activate [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The manipulation manager is deactivated, by default. The manager does not receive or respond to input and callbacks until **Activate** is called for the window.

Calls to **Activate** and [Deactivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager-deactivate) are reference counted.

#### Examples

The following example shows how to activate and deactivate input processing.

```
LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    BOOL handled = FALSE;
    switch ( msg )
    {
    case WM_SIZE:
        switch ( wParam)
        {
        case SIZE_MINIMIZED:
        case SIZE_MAXHIDE:
            pManipulationManager->Deactivate(hwnd);
            break;

        default:
            pManipulationManager->Activate(hwnd);
            break;
        }
        break;
    }
    if ( !handled)
    {
        return DefWindowProc(hwnd,msg,wParam,lParam);
    }
    else
    {
        return 0;
    }
}
```

## See also

[IDirectManipulationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager)