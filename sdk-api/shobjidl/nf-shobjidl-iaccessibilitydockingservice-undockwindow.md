# IAccessibilityDockingService::UndockWindow

## Description

Undocks the specified window handle if it is currently docked.

## Parameters

### `hwnd`

TBD

### `hWnd` [in]

Specifies the window that will be undocked.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ACCESSDENIED** | The window does not belong to the calling process. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_WINDOW_HANDLE)** | The window is not docked. |

## Remarks

This method can only be used to undock windows that belong to the calling process.

#### Examples

```
class CAccessibilityApplicationWindow : public IAccessibilityDockingServiceCallback
{

    ....
    ....

    HRESULT _Undock()
    {
        return _pDockingService->UndockWindow(_hwndMyApplication);
    }

    IAccessibilityDockingService *_pDockingService;
    HWND _hwndMyApplication;
}
```

## See also

[IAccessibilityDockingService](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iaccessibilitydockingservice)