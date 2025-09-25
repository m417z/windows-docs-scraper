# IStaticPortMappingCollection::get_Count

## Description

The
**get_Count** method retrieves the number of port mappings in the collection.

## Parameters

### `pVal` [out]

Pointer to a **long** variable that receives the number of port mappings in the collection.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The operation was aborted. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_NOTIMPL** | A specified method is not implemented. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## See also

[INATNumberOfEntriesCallback::NewNumberOfEntries](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nf-natupnp-inatnumberofentriescallback-newnumberofentries)

[IStaticPortMappingCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-istaticportmappingcollection)

[Network Address Translation Traversal Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-interfaces)

[Network Address Translation Traversal Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-reference)