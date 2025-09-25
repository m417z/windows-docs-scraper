# IBrowserService2::_PauseOrResumeView

## Description

Deprecated. Enables a derived class to request the base class to either pause (such as before a minimize operation) or resume the browser view.

## Parameters

### `fPaused` [in]

Type: **BOOL**

**TRUE** to indicate that the view is to be paused, **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.