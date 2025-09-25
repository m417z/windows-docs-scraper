# ISynchronizedInputProvider::StartListening

## Description

Starts listening for input of the specified type.

## Parameters

### `inputType` [in]

Type: **[SynchronizedInputType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-synchronizedinputtype)**

The type of input that is requested to be synchronized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When it finds matching input, the provider checks if the target UI Automation element matches the current element. If they match, the provider raises the [UIA_InputReachedTargetEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event; otherwise, it raises the [UIA_InputReachedOtherElementEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) or [UIA_InputDiscardedEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event. The UI Automation provider must discard the input if it is for an element other than this one.

This is a one-shot method; after receiving input, the provider stops listening and continues normally.

This method returns E_INVALIDOPERATION if the provider is already listening for input.

## See also

[ISynchronizedInputProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-isynchronizedinputprovider)