# IUPnPDescriptionDocument::get_ReadyState

## Description

The
**ReadyState** property specifies the status of the document load operation. This status indicates the state of the [IUPnPDescriptionDocument::Load](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-load) or [IUPnPDescriptionDocument::LoadAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-loadasync) method. These states are the standard ready-state values for loading XML documents.

## Parameters

### `plReadyState` [out]

Receives a reference to the ready state. The values this parameter can receive are (in the order they are used by Universal Plug and Play):

| plReadyState Value | Meaning |
| --- | --- |
| **READYSTATE_UNINITIALIZED** | The document object has been created. |
| **READYSTATE _LOADING** | The load operation has started. |
| **READYSTATE _COMPLETE** | The load operation is finished; the document has been downloaded and the XML has been parsed. |
| **READYSTATE _INTERACTIVE** | Reserved for future use. |
| **READYSTATE _LOADED** | Reserved for future use. |

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPDescriptionDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocument)

[IUPnPDescriptionDocument::Load](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-load)

[IUPnPDescriptionDocument::LoadAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-loadasync)