# INATNumberOfEntriesCallback::NewNumberOfEntries

## Description

The system calls the
**NewNumberOfEntries** method if the total number of NAT port mappings changes.

## Parameters

### `lNewNumberOfEntries` [in]

Specifies a **long** variable that contains the new number of port mappings.

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

## Remarks

The system calls this method when the total number of port mappings changes. The change in the total number of port mappings may be the result of a change in the number of dynamic port mappings. In this case, the system calls this method even though the number of static port mappings has not changed.

## See also

[INATEventManager::put_NumberOfEntriesCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nf-natupnp-inateventmanager-put_numberofentriescallback)

[INATNumberOfEntriesCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inatnumberofentriescallback)

[IStaticPortMappingCollection::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nf-natupnp-istaticportmappingcollection-get_count)

[Network Address Translation Traversal Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-interfaces)

[Network Address Translation Traversal Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-reference)