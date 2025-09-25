# IDataAdviseHolder::Advise

## Description

Creates a connection between an advise sink and a data object for receiving notifications.

## Parameters

### `pDataObject` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object for which notifications are requested. If data in this object changes, a notification is sent to the advise sinks that have requested notification.

### `pFetc` [in]

A pointer to a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that contains the specified format, medium, and target device that is of interest to the advise sink requesting notification. For example, one sink may want to know only when the bitmap representation of the data in the data object changes. Another sink may be interested in only the metafile format of the same object. Each advise sink is notified when the data of interest changes. This data is passed back to the advise sink when notification occurs.

### `advf` [in]

A group of flags that control the advisory connection. Possible values are from the [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) enumeration. However, only some of the possible **ADVF** values are relevant for this method. The following table briefly describes the relevant values; a more detailed description can be found in the description of the **ADVF** enumeration.

| Value | Meaning |
| --- | --- |
| **ADVF_NODATA** | Asks that no data be sent along with the notification. |
| **ADVF_ONLYONCE** | Causes the advisory connection to be destroyed after the first notification is sent. An implicit call to [IDataAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-unadvise) is made on behalf of the caller to remove the connection. |
| **ADVF_PRIMEFIRST** | Causes an initial notification to be sent regardless of whether data has changed from its current state. |
| **ADVF_DATAONSTOP** | When specified with ADVF_NODATA, this flag causes a last notification with the data included to be sent before the data object is destroyed. When ADVF_NODATA is not specified, this flag has no effect. |

### `pAdvise` [in]

A pointer to the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface on the advisory sink that receives the change notification.

### `pdwConnection` [out]

A pointer to a variable that receives a token that identifies this connection. The calling object can later delete the advisory connection by passing this token to [IDataAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-unadvise). If this value is zero, the connection was not established.

## Return value

This method returns S_OK on success.

## Remarks

Through the connection established through this method, the advisory sink can receive future notifications in a call to [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange).

An object issues a call to [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) to request notification on changes to the format, medium, or target device of interest. This data is specified in the *pFormatetc* parameter. The **DAdvise** method is usually implemented to call **IDataAdviseHolder::Advise** to delegate the task of setting up and tracking a connection to the advise holder. When the format, medium, or target device in question changes, the data object calls [IDataAdviseHolder::SendOnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-sendondatachange) to send the necessary notifications.

The established connection can be deleted by passing the value in *pdwConnection* in a call to [IDataAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-unadvise).

## See also

[CreateDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createdataadviseholder)

[IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder)

[IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise)