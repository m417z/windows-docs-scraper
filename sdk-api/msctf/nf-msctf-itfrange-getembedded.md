# ITfRange::GetEmbedded

## Description

The **ITfRange::GetEmbedded** method obtains content that corresponds to a [TS_CHAR_EMBEDDED](https://learn.microsoft.com/windows/desktop/TSF/ts-char--constants) character in the text stream. The start anchor of the range of text is positioned just before the character of interest.

## Parameters

### `ec` [in]

Edit cookie obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `rguidService` [in]

Identifier that specifies how the embedded content is obtained.

| Value | Meaning |
| --- | --- |
| **GUID_TS_SERVICE_ACCESSIBLE** | Output should be an [Accessible object](https://learn.microsoft.com/windows/desktop/WinAuto/accessible-objects). |
| **GUID_TS_SERVICE_ACTIVEX** | Caller requires a direct pointer to the object that supports the interface specified by *riid*. |
| **GUID_TS_SERVICE_DATAOBJECT** | Content should be obtained as an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) data transfer object, with *riid* being IID_IDataObject. Clients should specify this option when a copy of the content is required. |
| **Caller-defined** | Text services and context owners can define custom GUIDs. |

### `riid` [in]

UUID of the interface of the requested object.

### `ppunk` [out]

Pointer to the object. It can be cast to match *riid*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_NOTIMPL** | The implementing application does not expose embedded objects in its text stream. |
| **TF_E_NOINTERFACE** | The object does not support the requested interface. |
| **TF_E_NOLOCK** | The value in the *ec* parameter is an invalid cookie, or the caller does not have a read-only lock. |
| **TF_E_NOOBJECT** | The start anchor of the range is not positioned before a TF_CHAR_EMBEDDED character. |
| **TF_E_NOSERVICE** | The content cannot be returned to match *rguidService*. |

## Remarks

While the obtained object might not support certain interfaces, it is likely that the object will support those interfaces associated with embedded documents or controls such as **IOleObject**, **IDataObject**, **IViewObject**, **IPersistStorage**, **IOleCache**, or **IDispatch**. The caller must use **QueryInterface** to probe for any interesting interface. If the method succeeds but *riid* is **NULL**, the application indicates the presence of an embedded object but does not expose the object itself. Text processors can still benefit from a notification about the potential word break.

## See also

[Accessible Objects](https://learn.microsoft.com/windows/desktop/WinAuto/accessible-objects)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-insertembedded)

[Miscellaneous Framework Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)