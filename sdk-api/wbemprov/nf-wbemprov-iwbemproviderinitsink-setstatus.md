# IWbemProviderInitSink::SetStatus

## Description

The
**IWbemProviderInitSink::SetStatus** method indicates to Windows Management whether a provider is fully or partially initialized.

## Parameters

### `lStatus` [in]

Indicates to Windows Management a provider's initialization status. One of the following values can be set.

#### WBEM_S_INITIALIZED

Indicates that the provider is fully initialized and ready to accept requests.

#### WBEM_E_FAILED

Indicates that the provider has failed to initialize and is not functional.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

## Return value

This method always returns **WBEM_S_NO_ERROR**.

## Remarks

All types of providers call
**IWbemProviderInitSink::SetStatus** to indicate initialization status to Windows Management.

If *lStatus* is set to **WBEM_S_INITIALIZED**, Windows Management expects the provider to be fully capable of immediately servicing requests.

## See also

[IWbemProviderInitSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemproviderinitsink)

[Initializing a Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/initializing-a-provider)