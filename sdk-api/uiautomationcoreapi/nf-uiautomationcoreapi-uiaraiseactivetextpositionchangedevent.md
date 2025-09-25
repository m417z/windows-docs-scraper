# UiaRaiseActiveTextPositionChangedEvent function

## Description

Called by a provider to notify the Microsoft UI Automation core that the position within a text control has programmatically changed.

## Parameters

### `provider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider node where the position change within the text occurred.

### `textRange` [in, optional]

Type: **[ITextRangeProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)***

The text range change that occurred, if applicable.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also

[IUIAutomation6::AddActiveTextPositionChangedEventHandler](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomation6-addactivetextpositionchangedeventhandler), [IUIAutomation6::RemoveActiveTextPositionChangedEventHandler](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomation6-removeactivetextpositionchangedeventhandler), [IUIAutomationEventHandlerGroup::AddActiveTextPositionChangedEventHandler](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomationeventhandlergroup-addactivetextpositionchangedeventhandler)