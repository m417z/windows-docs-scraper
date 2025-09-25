# ITraceDataProvider::Query

## Description

Retrieves details about a registered provider.

## Parameters

### `bstrName` [in]

The name of the registered provider. The name is case-insensitive. You can also specify the string form of the provider's GUID.

### `bstrServer` [in]

The computer on which the provider is registered. You can specify the computer's name, fully qualified domain name, or IP address.

## Return value

Returns S_OK if successful.

## Remarks

To specify kernel providers, set the *bstrName* parameter to "Windows Kernel Trace".

To specify the context logger, set *bstrName* to "Circular Kernel Context Logger". The context logger provides a snapshot of the current state of the computer. The logger writes to an in-memory 100-megabyte circular log (not to a file). To release its contents to consumers, call the [IDataCollectorSet::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-commit) method to flush the session.

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)