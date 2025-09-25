# IUIEventingManager::SetEventLogger

## Description

Sets the event logger for ribbon events.

## Parameters

### `eventLogger` [in]

The event logger.

If NULL, disables event logging.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call [IUIFramework::Initialize](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-initialize) and [IUIFramework::LoadUI](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-loadui) before calling this method.

## See also

[IUIEventLogger](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuieventlogger)

[IUIEventingManager](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuieventingmanager)