# WSC_PROVIDER_INFO_TYPE enumeration

## Description

**Note** Layered Service Providers are deprecated. Starting with Windows 8 and Windows Server 2012, use [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page).

The Windows Sockets
**WSC_PROVIDER_INFO_TYPE**enumeration type is used to specify the information class of a layered service protocol (LSP) in Windows Sockets 2.

## Constants

### `ProviderInfoLspCategories`

The LSP category information for a protocol entry in a layered protocol. The information class should point to a DWORD value containing the appropriate LSP category flags implemented by LSP.

### `ProviderInfoAudit`

The LSP class information for audit information for the LSP entry. The information class should point to a [WSC_PROVIDER_AUDIT_INFO](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsc_provider_audit_info) structure containing an audit record for the LSP.

## Remarks

The
[WSC_PROVIDER_AUDIT_INFO](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsc_provider_audit_info) structure is not currently used.

## See also

[WSCGetProviderInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderinfo)

[WSCGetProviderInfo32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderinfo32)

[WSCSetProviderInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetproviderinfo)

[WSCSetProviderInfo32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetproviderinfo32)

[WSC_PROVIDER_AUDIT_INFO](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsc_provider_audit_info)