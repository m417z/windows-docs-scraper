# INATEventManager::put_NumberOfEntriesCallback

## Description

The **put_NumberOfEntriesCallback** method enables the NAT application with UPnP technology to register a callback interface with the NAT. The system calls the first method in this callback interface if the number of NAT port mappings changes.

## Parameters

### `pUnk` [in]

Pointer to an object that supports either the
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface or the
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface. See the Remarks section for more information.

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

The object referred to by *pUnk* must either support the
[INATNumberOfEntriesCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inatnumberofentriescallback) interface or the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface. The NAT first queries *pUnk* for the
**INATNumberOfEntriesCallback** interface. If this interface is not supported, the NAT queries *pUnk* for the **IDispatch** interface. If the **IDispatch** interface is not supported, the **NumberOfEntriesCallback** method returns E_FAIL.

If only [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) is supported, the NAT invokes the callback by calling [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) with the dispatch ID specified as zero, which indicates the default method. This **IDispatch** method is passed the same parameters as the
[INATNumberOfEntriesCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inatnumberofentriescallback) method, except that the first parameter passed is a string that indicates the reason the callback is invoked.

## See also

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)

[INATEventManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inateventmanager)

[INATNumberOfEntriesCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inatnumberofentriescallback)

[Network Address Translation Traversal Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-interfaces)

[Network Address Translation Traversal Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-reference)