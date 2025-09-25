# IInvokeProvider::Invoke

## Description

Sends a request to activate a control and initiate its single, unambiguous action.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IInvokeProvider::Invoke** is an asynchronous call and must return immediately without blocking.

**Note** This is particularly critical for controls that, directly or indirectly, launch a modal dialog when invoked.
Any Microsoft UI Automation client that instigated the event will remain blocked until the modal dialog is closed.

**IInvokeProvider::Invoke** raises the Invoked event after the control
has completed its associated action, if possible.

The event should be raised before servicing the Invoke request
in the following scenarios:

* It is not possible or practical to wait until the action is complete.
* The action requires user interaction.
* The action is time-consuming and will cause the calling client to block for a significant length of time.

## See also

[IInvokeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iinvokeprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)