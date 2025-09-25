# UiaRaiseTextEditTextChangedEvent function

## Description

Called by a provider to notify the Microsoft UI Automation core that a text control has programmatically changed text.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider node where the text change occurred.

### `textEditChangeType` [in]

Type: **[TextEditChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-texteditchangetype)**

The type of text-edit change that occurred.

### `pChangedData` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)***

The event data. Should be assignable as a **VAR** of type **VT_BSTR**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is a helper function for providers that implement [ITextEditProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itexteditprovider) and are raising the pattern's required events. Follow the guidance given in [TextEdit Control Pattern](https://learn.microsoft.com/windows/desktop/WinAuto/textedit-control-pattern) that describes when to raise the events and what payload the events should pass to UI Automation.

If there are no clients listening for a particular change type, no event is raised.

The event data should contain different payloads for each change type (per [TextEditChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-texteditchangetype)):

* **TextEditChangeType_AutoCorrect**: *pChangedData* should be the new corrected string .
* **TextEditChangeType_Composition**: *pChangedData* should be the updated string in the composition (only the part that changed).
* **TextEditChangeType_CompositionFinalized**: *pChangedData* should be the finalized string of the completed composition (this may be empty if composition was canceled or deleted).

## See also

[HandleTextEditTextChangedEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextedittextchangedeventhandler-handletextedittextchangedevent)

[ITextEditProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itexteditprovider)

[IUIAutomation3::AddTextEditTextChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation3-addtextedittextchangedeventhandler)

[TextEdit Control Pattern](https://learn.microsoft.com/windows/desktop/WinAuto/textedit-control-pattern)