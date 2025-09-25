# IUIAutomationSynchronizedInputPattern::StartListening

## Description

Causes the Microsoft UI Automation provider to start listening for mouse or keyboard input.

## Parameters

### `inputType` [in]

Type: **[SynchronizedInputType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-synchronizedinputtype)**

A combination of values specifying the type of input to listen for.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When matching input is found, the provider checks whether the target element matches the current element. If they match, the provider raises the [UIA_InputReachedTargetEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event; otherwise it raises the [UIA_InputReachedOtherElementEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) or [UIA_InputDiscardedEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event.

After receiving input of the specified type, the provider stops checking for input and continues as normal.

If the provider is already listening for input, this method returns **E_INVALIDOPERATION**.

## See also

[IUIAutomationSynchronizedInputPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationsynchronizedinputpattern)