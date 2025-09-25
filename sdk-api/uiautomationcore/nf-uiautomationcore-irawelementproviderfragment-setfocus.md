# IRawElementProviderFragment::SetFocus

## Description

Sets the focus to this element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Microsoft UI Automation framework will ensure that the part of the interface that hosts this fragment is
already focused before calling this method. Your implementation should update only its internal focus state;
for example, by repainting a list item to show that it has the focus. If you prefer that UI Automation
not focus the parent window, set [ProviderOptions_ProviderOwnsSetFocus](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-provideroptions) in [IRawElementProviderSimple::ProviderOptions](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementprovidersimple-get_provideroptions) for the fragment root.

## See also

[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)