# IWRdsProtocolListener::GetSettings

## Description

Gets the listener setting information for client connection requests.

## Parameters

### `WRdsListenerSettingLevel` [in]

The listener setting level to use.

### `pWRdsListenerSettings` [out]

A pointer to a [WRDS_LISTENER_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_listener_settings) structure that contains the returned listener settings.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails,
return an **HRESULT** value that indicates the error. For a list of common error codes,
see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollistener)