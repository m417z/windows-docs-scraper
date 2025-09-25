# IBrowserService2::_OnFocusChange

## Description

Deprecated. Coordinates focus between the base and the derived class when the focus shifts between the derived class's browser toolbars and its view.

## Parameters

### `itb` [in]

Type: **UINT**

The ID of the toolbar gaining focus, or ITB_VIEW if the view is gaining focus.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.