# TRACE_PROVIDER_INFO structure

## Description

Defines the GUID and name for a provider.

## Members

### `ProviderGuid`

GUID that uniquely identifies the provider.

### `SchemaSource`

Is zero if the provider uses a XML manifest to provide a description of its events. Otherwise, the value is 1 if the provider uses a WMI MOF class to provide a description of its events.

### `ProviderNameOffset`

Offset to a null-terminated Unicode string that contains the name of the provider. The offset is from the beginning of the [PROVIDER_ENUMERATION_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_enumeration_info) buffer that [TdhEnumerateProviders](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviders) returns.

## See also
[PROVIDER_ENUMERATION_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_enumeration_info)