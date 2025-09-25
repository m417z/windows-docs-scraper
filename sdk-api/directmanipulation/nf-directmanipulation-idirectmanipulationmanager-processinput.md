# IDirectManipulationManager::ProcessInput

## Description

Passes keyboard and mouse messages to the manipulation manager on the app's UI thread.

## Parameters

### `message` [in]

The input message to process.

### `handled` [out, retval]

**TRUE** if no further processing should be done with this message; otherwise, **FALSE**.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method for mouse and keyboard input.

#### Examples

The following example shows how to pass messages to the manipulation manager.

```
LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    BOOL handled = FALSE;

LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    BOOL handled = FALSE;
    switch (msg)
    {
    case WM_KEYDOWN:
    case WM_POINTERWHEEL:
    case WM_POINTERHWHEEL:
    case WM_MOUSEWHEEL:
    case WM_MOUSEHWHEEL:
        MSG msg = {};
        msg.hwnd = hwnd;
        msg.message = message;
        msg.lParam = lParam;
        msg.wParam = wParam;

        if (FAILED(m_pManipulationManager->ProcessInput(&msg, &handled)))
        {
            handled = false;
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