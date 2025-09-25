# IOleAdviseHolder::Unadvise

## Description

Deletes a previously established advisory connection.

## Parameters

### `dwConnection` [in]

The value previously returned by [IOleAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-advise) in *pdwConnection*.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOCONNECTION** | The *dwConnection* parameter does not represent a valid advisory connection. |

## Remarks

**IOleAdviseHolder::Unadvise** is intended to be used to implement [IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise) to delete an advisory connection. In general, you would use the OLE advise holder having obtained a pointer through a call to [CreateOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createoleadviseholder).

Typically, containers call this method at shutdown or when an object is deleted. In certain cases, containers could call this method on objects that are running but not currently visible, as a way of reducing the overhead of maintaining multiple advisory connections.

## See also

[IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder)

[IOleAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-advise)

[IOleAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-enumadvise)

[IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise)