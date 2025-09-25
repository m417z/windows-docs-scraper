# IWindowProvider::Close

## Description

Attempts to close the window.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IWindowProvider::Close** must return immediately without blocking.

**IWindowProvider::Close** raises the [UIA_Window_WindowClosedEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids)
event.
If possible, the event should be raised after the control has completed its associated action.

When called on a split pane control, this method will close the pane and remove
the associated split.

This method may also close all other panes depending on implementation.

## See also

[IWindowProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iwindowprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)