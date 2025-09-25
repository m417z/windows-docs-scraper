# PROVIDER_ENUMERATION_INFO structure

## Description

Defines the array of providers that have registered a MOF or manifest on the computer.

## Members

### `NumberOfProviders`

Number of elements in the **TraceProviderInfoArray** array.

### `Reserved`

### `TraceProviderInfoArray`

Array of [TRACE_PROVIDER_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-trace_provider_info) structures that contain information about each provider such as its name and unique identifier.

#### - Padding

Reserved.

## See also
[TdhEnumerateProviders](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviders)