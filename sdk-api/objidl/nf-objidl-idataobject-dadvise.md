# IDataObject::DAdvise

## Description

Called by an object supporting an advise sink to create a connection between a data object and the advise sink. This enables the advise sink to be notified of changes in the data of the object.

## Parameters

### `pformatetc` [in]

A pointer to a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that defines the format, target device, aspect, and medium that will be used for future notifications. For example, one sink may want to know only when the bitmap representation of the data in the data object changes. Another sink may be interested in only the metafile format of the same object. Each advise sink is notified when the data of interest changes. This data is passed back to the advise sink when notification occurs.

### `advf` [in]

A group of flags for controlling the advisory connection. Possible values are from the [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) enumeration. However, only some of the possible **ADVF** values are relevant for this method. The following table briefly describes the relevant values.

| ADVF Value | Description |
| --- | --- |
| ADVF_NODATA | Asks the data object to avoid sending data with the notifications. Typically data is sent. This flag is a way to override the default behavior. When ADVF_NODATA is used, the **tymed** member of the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure that is passed to [OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) will usually contain TYMED_NULL. The caller can then retrieve the data with a subsequent [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) call. |
| ADVF_ONLYONCE | Causes the advisory connection to be destroyed after the first change notification is sent. An implicit call to [IDataObject::DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise) is made on behalf of the caller to remove the connection. |
| ADVF_PRIMEFIRST | Asks for an additional initial notification. The combination of ADVF_ONLYONCE and ADVF_PRIMEFIRST provides, in effect, an asynchronous [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) call. |
| ADVF_DATAONSTOP | When specified with ADVF_NODATA, this flag causes a last notification with the data included to be sent before the data object is destroyed.<br><br>If used without ADVF_NODATA, **DAdvise** can be implemented in one of the following ways:<br><br>* The ADVF_DATAONSTOP can be ignored.<br>* The object can behave as if ADVF_NODATA was specified.<br><br>A change notification is sent only in the shutdown case. Data changes prior to shutdown do not cause a notification to be sent. |

### `pAdvSink` [in]

A pointer to the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface on the advisory sink that will receive the change notification.

### `pdwConnection` [out]

A token that identifies this connection. You can use this token later to delete the advisory connection (by passing it to [IDataObject::DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise)). If this value is 0, the connection was not established.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | This method is not implemented on the data object. |
| **DV_E_LINDEX** | The value for **lindex** is not valid; currently, only -1 is supported. |
| **DV_E_FORMATETC** | The value for *pformatetc* is not valid. |
| **OLE_E_ADVISENOTSUPPORTED** | The data object does not support change notification. |

## Remarks

**DAdvise** creates a change notification connection between a data object and the caller. The caller provides an advisory sink to which the notifications can be sent when the object's data changes.

Objects used simply for data transfer typically do not support advisory notifications and return OLE_E_ADVISENOTSUPPORTED from **DAdvise**.

### Notes to Callers

The object supporting the advise sink calls **DAdvise** to set up the connection, specifying the format, aspect, medium, and/or target device of interest in the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure passed in. If the data object does not support one or more of the requested attributes or the sending of notifications at all, it can refuse the connection by returning OLE_E_ADVISENOTSUPPORTED.

Containers of linked objects can set up advisory connections directly with the bound link source or indirectly through the standard OLE link object that manages the connection. Connections set up with the bound link source are not automatically deleted. The container must explicitly call [IDataObject::DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise) on the bound link source to delete an advisory connection. The OLE link object, manipulated through the [IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink) interface, is implemented in the default handler. Connections set up through the OLE link object are destroyed when the link object is deleted.

The OLE default link object creates a "wildcard advise" with the link source so OLE can maintain the time of last change. This advise is specifically used to note the time that anything changed. OLE ignores all data formats that may have changed, noting only the time of last change. To allow wildcard advises, set the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) members as follows before calling **DAdvise**:

``` syntax
cf == 0;
ptd == NULL;
dwAspect == -1;
lindex == -1
tymed == -1;
```

The advise flags should also include ADVF_NODATA. Wildcard advises from OLE should always be accepted by applications.

### Notes to Implementers

To simplify the implementation of **DAdvise** and the other notification methods in [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) ([DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise) and [EnumDAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumdadvise)) that supports notification, OLE provides an advise holder object that manages the registration and sending of notifications. To get a pointer to this object, call the helper function [CreateDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createdataadviseholder) on the first invocation of **DAdvise**. This supplies a pointer to the object's [IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder) interface. Then, delegate the call to the [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise) method in the data advise holder, which creates, and subsequently manages, the requested connection.

## See also

[CreateDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createdataadviseholder)

[IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)