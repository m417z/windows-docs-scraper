# IInputPanelConfiguration::EnableFocusTracking

## Description

Enables a client process to opt-in to the focus tracking mechanism for Windows Store apps that controls the invoking and dismissing semantics of the touch keyboard.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note**

This method will not work in Windows 10. A user can manually configure settings through the notification center or through the **Typing** settings to enable pulling up a touch keyboard automatically when focusing on an edit control.

## See also

[IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration)