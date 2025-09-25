# UiaDisconnectProvider function

## Description

Releases all references that a particular provider holds to Microsoft UI Automation objects.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider to be disconnected.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A provider should call this function to clean up UI Automation resources that are associated with a UI element that was destroyed. The DLL associated with the UI element can be safely unloaded after the function returns.

After this function returns, all client requests that are associated with the disconnected provider receive the [UIA_E_ELEMENTNOTAVAILABLE](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-error-codes)
error code.

This function cannot be called in response to a call to the [SendMessage](https://learn.microsoft.com/windows/desktop/DevNotes/-sendmessage) function. An application cannot make outbound Component Object Model (COM) calls in response to a call to **SendMessage**, and releasing a provider is typically an outbound COM call. The **UiaDisconnectProvider** function returns RPC_E_CANTCALLOUT_ININPUTSYNCCALL if the function is called in response to a **SendMessage** call. You can use the [InSendMessageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessageex) function to determine whether a particular message is being handled in response to a **SendMessage** call.

An application that calls **UiaDisconnectProvider** should not respond to a re-entrant [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message by returning a pointer to the provider that it is trying to disconnect. If the application tries to disconnect a provider, but then calls the [UiaReturnRawElementProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiareturnrawelementprovider) function with that same provider during the disconnect attempt, the provider might not be fully disconnected.

## See also

[Functions for Providers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-functions)

[UiaDisconnectAllProviders](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiadisconnectallproviders)