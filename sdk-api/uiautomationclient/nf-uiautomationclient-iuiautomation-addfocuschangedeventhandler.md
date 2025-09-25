# IUIAutomation::AddFocusChangedEventHandler

## Description

Registers a method that handles focus-changed events.

**Note** Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

## Parameters

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

Type: **[IUIAutomationFocusChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationfocuschangedeventhandler)***

A pointer to the object that handles the event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Focus-changed events are system-wide; you cannot set a narrower scope.

A UI Automation client should not use multiple threads to add or remove event handlers. Unexpected behavior can result if one event handler is being added or removed while another is being added or removed in the same client process.

#### Examples

The following example function creates an object that implements [IUIAutomationFocusChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationfocuschangedeventhandler) and subscribes to the event by adding the handler.

```cpp
HRESULT AddFocusHandler(IUIAutomation* pAutomation)
{
    // CFocusHandler is a class that implements IUIAutomationFocusChangedEventHandler.
    CFocusHandler* pFocusHandler = new CFocusHandler();
    if (!pFocusHandler)
    {
        return E_OUTOFMEMORY;
    }
    IUIAutomationFocusChangedEventHandler* pHandler;
    pFocusHandler->QueryInterface(IID_IUIAutomationFocusChangedEventHandler, (void**)&pHandler);
    HRESULT hr = pAutomation->AddFocusChangedEventHandler(NULL, pHandler);
    pFocusHandler->Release();
    return hr;
}

```

## See also

[Caching UI Automation Properties and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-cachingforclients)

**Conceptual**

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomationFocusChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationfocuschangedeventhandler)

**Reference**

[RemoveAllEventHandlers](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removealleventhandlers)

[RemoveFocusChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-removefocuschangedeventhandler)

[Subscribing to UI Automation Events](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-eventsforclients)

[Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading)