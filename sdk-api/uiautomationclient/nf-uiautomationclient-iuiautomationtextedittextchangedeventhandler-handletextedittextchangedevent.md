# IUIAutomationTextEditTextChangedEventHandler::HandleTextEditTextChangedEvent

## Description

Handles an event that is raised when a Microsoft UI Automation provider for a text-edit control reports a programmatic text change.

## Parameters

### `sender` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the element that raised the event.

### `textEditChangeType` [in]

Type: **[TextEditChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-texteditchangetype)**

The type of text-edit change that occurred.

### `eventStrings` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)***

Event data passed by the event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is implemented by the application to handle events that it has subscribed to by using **AddTextEditTextChangedEventHandler**.

The event data contains different payloads for each text-edit change type:

* **TextEditChangeType_AutoCorrect**: Data is the new corrected string .
* **TextEditChangeType_Composition**: Data is the updated string in the composition (only the part that changed).
* **TextEditChangeType_CompositionFinalized**: Data is the finalized string of the completed composition (this may be empty if composition was canceled or deleted).

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

[IUIAutomationTextEditTextChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextedittextchangedeventhandler)