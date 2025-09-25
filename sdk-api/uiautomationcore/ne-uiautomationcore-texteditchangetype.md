# TextEditChangeType enumeration

## Description

Describes the text editing change being performed by controls when text-edit events are raised or handled.

## Constants

### `TextEditChangeType_None:0`

Not related to a specific change type.

### `TextEditChangeType_AutoCorrect:1`

Change is from an auto-correct action performed by a control.

### `TextEditChangeType_Composition:2`

Change is from an IME active composition within a control.

### `TextEditChangeType_CompositionFinalized:3`

Change is from an IME composition going from active to finalized state within a control.

**Note** The finalized string may be empty if composition was canceled or deleted.

### `TextEditChangeType_AutoComplete:4`

## See also

[ITextEditProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itexteditprovider)

[Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids)

[UiaRaiseTextEditTextChangedEvent function](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraisetextedittextchangedevent)