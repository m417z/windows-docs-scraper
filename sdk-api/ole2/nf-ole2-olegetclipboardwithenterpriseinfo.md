# OleGetClipboardWithEnterpriseInfo function

## Description

Enables Windows Information Protection enlightened
applications to retrieve an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) from the OLE Clipboard
accompanied by Windows Information Protection information about the data and the
source application.This information allows the
enlightened application to take over responsibility for applying Windows Information Protection
policy, including flying any appropriate UI prompts, and
auditing cases where the user explicitly approves copying
enterprise data into a personal context.

If the calling application is not enlightened, or is
configured as "unallowed" to access enterprise data,
then this call behaves exactly like [OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) - applying policy before deciding what [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) to return,
and supplying empty strings as output.

## Parameters

### `dataObject` [out]

Address of [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer variable that receives the interface pointer to the clipboard data object.

### `dataEnterpriseId` [out]

The enterprise id of the application that set the clipboard data.
If the data is personal, this will be an empty string.

### `sourceDescription` [out]

 The description of the application that set the clipboard.

### `targetDescription` [out]

The description of the caller's application to be used in auditing.

### `dataDescription` [out]

The description of the data object to be used in auditing.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **CLIPBRD_E_CANT_OPEN** | The [OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard) function used within [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) failed. |
| **CLIPBRD_E_CANT_CLOSE** | The [CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard) function used within [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) failed. |

## Remarks

**Caution** Clipboard data is not trusted. Parse the data carefully before using it in your application.

If you are writing an application that can accept data from the clipboard, call the **OleGetClipboardWithEnterpriseInfo** function to get a pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface that you can use to retrieve the contents of the clipboard.

**OleGetClipboardWithEnterpriseInfo** handles three cases:

* The application that placed data on the clipboard with the [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) function is still running.
* The application that placed data on the clipboard with the [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) function has subsequently called the [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) function.
* There is data from a non-OLE application on the clipboard.

In the first case, the clipboard data object returned by **OleGetClipboardWithEnterpriseInfo** may forward calls as necessary to the original data object placed on the clipboard and, thus, can potentially make RPC calls.

In the second case, OLE creates a default data object and returns it to the user. Because the data on the clipboard originated from an [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) call, the OLE-provided data object contains more accurate information about the type of data on the clipboard. In particular, the original medium (TYMED) on which the data was offered is known. Thus, if a data-source application offers a particular clipboard format, for example cfFOO, on a storage object and calls the [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) function, the storage object is copied into memory and the hglobal memory handle is put on the clipboard. Then, when the **OleGetClipboardWithEnterpriseInfo** function creates its default data object, the hglobal from the clipboard again becomes an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) object. Furthermore, the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumerator and the [IDataObject::QueryGetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-querygetdata) method would all correctly indicate that the original clipboard format (cfFOO) is again available on a TYMED_ISTORAGE.

In the third case, OLE still creates a default data object, but there is no special information about the data in the clipboard formats (particularly for application-defined Clipboard formats). Thus, if an hGlobal-based storage medium were put on the clipboard directly by a call to the [SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata) function, the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumerator and the [IDataObject::QueryGetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-querygetdata) method would not indicate that the data was available on a storage medium. A call to the [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method for TYMED_ISTORAGE would succeed, however. Because of these limitations, it is strongly recommended that OLE-aware applications interact with the clipboard using the OLE clipboard functions.

The clipboard data object created by the **OleGetClipboardWithEnterpriseInfo** function has a fairly extensive [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) implementation. The OLE-provided data object can convert OLE 1 clipboard format data into the representation expected by an OLE 2 caller. Also, any structured data is available on any structured or flat medium, and any flat data is available on any flat medium. However, GDI objects (such as metafiles and bitmaps) are only available on their respective mediums.

Note that the tymed member of the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure used in the **FORMATETC** enumerator contains the union of supported mediums. Applications looking for specific information (such as whether CF_TEXT is available on TYMED_HGLOBAL) should do the appropriate bitmasking when checking this value.

If you call the **OleGetClipboardWithEnterpriseInfo** function, you should only hold on to the returned [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) for a very short time. It consumes resources in the application that offered it.

## See also

[OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard)

[OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard)