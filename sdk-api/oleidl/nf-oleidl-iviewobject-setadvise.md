# IViewObject::SetAdvise

## Description

Establishes a connection between the view object and an advise sink so that the advise sink can be notified about changes in the object's view.

## Parameters

### `aspects` [in]

View for which the advisory connection is being set up. Valid values are taken from the enumeration [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect). See the **DVASPECT** enumeration for more information.

### `advf` [in]

Contains a group of flags for controlling the advisory connection. Valid values are from the enumeration [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf). However, only some of the possible **ADVF** values are relevant for this method. The following table briefly describes the relevant values. See the **ADVF** enumeration for a more detailed description.

| Value | Meaning |
| --- | --- |
| **ADVF_ONLYONCE** | Causes the advisory connection to be destroyed after the first notification is sent. |
| **ADVF_PRIMEFIRST** | Causes an initial notification to be sent regardless of whether data has changed from its current state. |

**Note** The ADVF_ONLYONCE and ADVF_PRIMEFIRST can be combined to provide an asynchronous call to [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata).

### `pAdvSink` [in]

Pointer to the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface on the advisory sink that is to be informed of changes. A **NULL** value deletes any existing advisory connection.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_ADVISENOTSUPPORTED** | Advisory notifications are not supported. |
| **DV_E_DVASPECT** | Invalid value for *dwAspect*. |
| **E_INVALIDARG** | One or more of the supplied values is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |

## Remarks

A container application that is requesting a draw operation on a view object can also register with the **IViewObject::SetAdvise** method to be notified when the presentation of the view object changes. To find out about when an object's underlying data changes, you must call [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) separately.

To remove an existing advisory connection, call the **IViewObject::SetAdvise** method with *pAdvSink* set to **NULL**.

If the view object changes, a call is made to the appropriate advise sink through its [IAdviseSink::OnViewChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onviewchange) method.

At any time, a given view object can support only one advisory connection. Therefore, when **IViewObject::SetAdvise** is called and the view object is already holding on to an advise sink pointer, OLE releases the existing pointer before the new one is registered.

## See also

[ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf)

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[IViewObject::GetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-getadvise)