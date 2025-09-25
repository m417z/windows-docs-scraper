# IWRdsProtocolShadowConnection::Start

## Description

Notifies the protocol that shadowing has started.

## Parameters

### `pTargetServerName` [in]

A pointer to a string that contains the name of the shadowing server.

### `TargetSessionId` [in]

An integer that specifies the ID of the target session to shadow.

### `HotKeyVk` [in]

The virtual key code of the key that must be pressed to stop shadowing. This key is used in combination with the *HotkeyModifiers* parameter.

### `HotkeyModifiers` [in]

The virtual modifier that specifies the modifier key to press to stop shadowing. Modifier keys include the Shift, Alt, and Ctrl keys. The modifier key is used in combination with the key signified by the *HotKeyVk* parameter.

### `pShadowCallback` [in]

A pointer to an [IWRdsProtocolShadowCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolshadowcallback) interface that the protocol can use to call back into the Remote Desktop Services service.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The Remote Desktop Services service also changes the session state on the shadowed client to reflect the fact that it is being shadowed.

## See also

[IWRdsProtocolShadowConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolshadowconnection)