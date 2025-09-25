# ITraceDataProvider::GetRegisteredProcesses

## Description

Retrieves a list of processes that have registered as an Event Tracing for Windows (ETW) provider.

## Parameters

### `Processes` [out]

An [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface that contains the list of processes that have registered as an ETW provider. The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the name of the binary, and the [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the process identifier.

## Return value

Returns S_OK if successful.

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)