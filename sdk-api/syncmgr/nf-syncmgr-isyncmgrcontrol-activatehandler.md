# ISyncMgrControl::ActivateHandler

## Description

Activates or deactivates a handler.

## Parameters

### `fActivate` [in]

Type: **BOOL**

**TRUE** to activate; **FALSE** to deactivate.

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the handler. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `hwndOwner` [in]

Type: **HWND**

A handle to a window that can be used by the handler to display any necessary UI. This value can be **NULL**.

### `nControlFlags` [in]

Type: **[SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags)**

A value from the [SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags) enumeration specifying whether the activation or deactivation of the handler should be performed synchronously or asynchronously.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An active handler appears in the Sync Center folder; an inactive handler appears in the Sync Setup folder.

If the specified handler returns [SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) or [SYNCMGR_HCM_QUERY_BEFORE_DEACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) in the mask returned from the [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities) method, the query operation is requested before the handler is activated or deactivated. If no query UI is requested or once the user confirms the operation, the handler's [Activate](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-activate) method is called.

If SYNCMGR_CF_WAIT is set in the *nControlFlags* parameter, **ActivateHandler** does not return until Sync Center has processed this notification.

#### Examples

The following example shows the usage of **ISyncMgrControl::ActivateHandler** by a handler's procedure.

```cpp
void MiscProc(...)
{
    ...

    // Get the Sync Center control object.
    ISyncMgrControl *pControl = NULL;

    hr = CoCreateInstance(CLSID_SyncMgrControl,
                          CLSCTX_SERVER,
                          IID_PPV_ARGS(&pControl));
    if (SUCCEEDED(hr))
    {
        // Tell Sync Center to activate our handler.
        hr = pControl->ActivateHandler(TRUE,
                                       s_szMySyncHandlerID,
                                       hwndOwner,
                                       SYNCMGR_CF_NOWAIT);
        pControl->Release();
    }

    ...

}

```