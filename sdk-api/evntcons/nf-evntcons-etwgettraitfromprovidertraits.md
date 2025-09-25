# EtwGetTraitFromProviderTraits function (evntcons.h)

## Description

Retrieves an individual trait from the ETW provider.

## Parameters

### `ProviderTraits` [in]

The Provider traits.

### `TraitType` [in]

The [ETW_PROVIDER_TRAIT_TYPE](https://learn.microsoft.com/windows/win32/api/evntcons/ne-evntcons-etw_provider_trait_type).

### `Trait` [out]

The Provider trait.

### `Size` [out]

The trait size.

## Return value

Returns ERROR_SUCCESS if successful.

## Remarks

Providers are applications that can generate event logs.

## See also