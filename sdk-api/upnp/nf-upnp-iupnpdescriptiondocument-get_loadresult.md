# IUPnPDescriptionDocument::get_LoadResult

## Description

The
**LoadResult** property specifies the success or failure code of a completed load operation.

## Parameters

### `phrError` [out]

Receives a reference to the success or failure code. The values this parameter can receive are:

| phrError Value | Meaning |
| --- | --- |
| **E_FAIL** | The load operation failed. |
| **E_PENDING** | The load operation is not yet completed. |
| **E_UNEXPECTED** | An unexpected error occurred during the load operation. |
| **S_OK** | The load operation succeeded. |

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This property specifies the error that the [IUPnPDescriptionDocument::Load](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-load) or [IUPnPDescriptionDocument::LoadAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-loadasync) method generates. This property is useful when it is necessary to separate the load operation from the error checking.

## See also

[IUPnPDescriptionDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocument)

[IUPnPDescriptionDocument::Load](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-load)

[IUPnPDescriptionDocument::LoadAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-loadasync)