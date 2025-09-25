# ITextStoreACP::GetEmbedded

## Description

Gets an embedded document.

## Parameters

### `acpPos` [in]

Contains the character position, within the document, from where the object is obtained.

### `rguidService` [in]

Contains a GUID value that defines the requested format of the obtained object. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GUID_TS_SERVICE_DATAOBJECT** | The object should be obtained as an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object. |
| **GUID_TS_SERVICE_ACCESSIBLE** | The object should be obtained as an [Accessible object](https://learn.microsoft.com/windows/desktop/WinAuto/accessible-objects). |
| **GUID_TS_SERVICE_ACTIVEX** | The object should be obtained as an ActiveX object. |

### `riid` [in]

Specifies the interface type requested.

### `ppunk` [out]

Pointer to an **IUnknown** pointer that receives the requested interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_NOTIMPL** | The application does not support embedded objects. |
| **TF_E_INVALIDPOS** | *acpPos* is not within the document. |
| **TS_E_NOINTERFACE** | The requested interface type is unsupported. |
| **TS_E_NOLOCK** | The caller does not have a read-only lock. |
| **TS_E_NOOBJECT** | There is no embedded object at *acpPos*. |
| **TS_E_NOSERVICE** | The service type specified in *rguidService* is unsupported. |

## Remarks

The caller must use **QueryInterface** to probe for appropriate interfaces. Prospective interfaces include those associated with embedded documents or controls such as **IOleObject** , **IDataObject** , **IViewObject** , **IPersistStorage** , **IOleCache** , or **IDispatch** .

## See also

[Accessible Objects](https://learn.microsoft.com/windows/desktop/WinAuto/accessible-objects)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)