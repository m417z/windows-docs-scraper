# ITextEditProvider::GetActiveComposition

## Description

Returns the active composition.

## Parameters

### `pRetVal` [out, retval]

Type: **[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)****

Pointer to the range of the current conversion (none if there is no conversion).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Follow the guidance given in [TextEdit Control Pattern](https://learn.microsoft.com/windows/desktop/WinAuto/textedit-control-pattern) that describes how to implement this method and how to raise the related notification events.

## See also

**Conceptual**

[ITextEditProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itexteditprovider)

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

**Reference**

[TextEdit Control Pattern](https://learn.microsoft.com/windows/desktop/WinAuto/textedit-control-pattern)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)

[UiaRaiseTextEditTextChangedEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraisetextedittextchangedevent)