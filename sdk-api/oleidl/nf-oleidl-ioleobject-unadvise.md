# IOleObject::Unadvise

## Description

Deletes a previously established advisory connection.

## Parameters

### `dwConnection` [in]

Contains a token of nonzero value, which was previously returned from [IOleObject::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise) through its *pdwConnection* parameter.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **OLE_E_NOCONNECTION** | dwConnection does not represent a valid advisory connection. |

## Remarks

Normally, containers call **IOleObject::Unadvise** at shutdown or when an object is deleted. In certain cases, containers can call this method on objects that are running but not currently visible as a way of reducing the overhead of maintaining multiple advisory connections. The easiest way to implement this method is to delegate the call to **IOleObject::Unadvise**.

## See also

[IOleAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-unadvise)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise)

[IOleObject::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumadvise)