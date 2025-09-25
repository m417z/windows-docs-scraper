# IWRdsProtocolManager::Uninitialize

## Description

Uninitializes the protocol manager.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You can implement this method to clean up resources used by the [Initialize](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-initialize) method. For example, if the **Initialize** method added a reference to an [IWRdsProtocolSettings](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolsettings) object pointer, the **Uninitialize** method can release that reference.

## See also

[IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager)

[Initialize](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-initialize)