# WSC_PROVIDER_AUDIT_INFO structure

## Description

**Note** Layered Service Providers are deprecated. Starting with Windows 8 and Windows Server 2012, use [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page).

The
**WSC_PROVIDER_AUDIT_INFO** structure contains audit information for a layered service provider (LSP) entry in Windows Sockets 2.

## Members

### `RecordSize`

The size, in bytes of this audit information record which includes this member.

### `Reserved`

A reserved member for the audit information record.

## Remarks

The
**WSC_PROVIDER_AUDIT_INFO** structure is not currently used.

## See also

[WSCGetProviderInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderinfo)

[WSCGetProviderInfo32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderinfo32)

[WSCSetProviderInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetproviderinfo)

[WSCSetProviderInfo32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetproviderinfo32)

[WSC_PROVIDER_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ne-ws2spi-wsc_provider_info_type)