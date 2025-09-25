# IDirectManipulationViewportEventHandler::OnViewportStatusChanged

## Description

Called when the status of a viewport changes.

## Parameters

### `viewport` [in]

The viewport for which status has changed.

### `current` [in]

The new status of the viewport.

### `previous` [in]

The previous status of the viewport.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you call [GetStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-getstatus) from within this handler, the status returned is not guaranteed to be the same as at the time of the call. This is because of the asynchronous nature of the notification.

## See also

[IDirectManipulationViewportEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewporteventhandler)