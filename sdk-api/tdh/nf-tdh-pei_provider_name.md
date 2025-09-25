# PEI_PROVIDER_NAME function (tdh.h)

## Description

Macro that retrieves the Provider Event Info (PEI) name.

## Parameters

### `ProviderEnum`

The array of providers that have registered a MOF or manifest on the computer ([PROVIDER_ENUMERATION_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-provider_enumeration_info))

### `ProviderInfo`

Provider event info ([PROVIDER_EVENT_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-provider_event_info)).

## Return value

The provider name, or NULL.

## Remarks

## See also