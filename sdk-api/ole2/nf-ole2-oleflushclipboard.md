# OleFlushClipboard function

## Description

Carries out the clipboard shutdown sequence. It also releases the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer that was placed on the clipboard by the [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) function.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **CLIPBRD_E_CANT_OPEN** | The Windows OpenClipboard function used within [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) failed. |
| **CLIPBRD_E_CANT_CLOSE** | The Windows CloseClipboard function used within [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) failed. |

## Remarks

**OleFlushClipboard** renders the data from a data object onto the clipboard and releases the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer to the data object. While the application that put the data object on the clipboard is running, the clipboard holds only a pointer to the data object, thus saving memory. If you are writing an application that acts as the source of a clipboard operation, you can call the **OleFlushClipboard** function when your application is closed, such as when the user exits from your application. Calling **OleFlushClipboard** enables pasting and paste-linking of OLE objects after application shutdown.

Before calling **OleFlushClipboard**, you can easily determine if your data is still on the clipboard with a call to the [OleIsCurrentClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleiscurrentclipboard) function.

**OleFlushClipboard** leaves all formats offered by the data transfer object, including the OLE 1 compatibility formats, on the clipboard so they are available after application shutdown. In addition to OLE 1 compatibility formats, these include all formats offered on a global handle medium (all except for TYMED_FILE) and formatted with a **NULL** target device. For example, if a data-source application offers a particular clipboard format (say cfFOO) on an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) object, and calls the **OleFlushClipboard** function, the storage object is copied into memory and the hglobal memory handle is put on the clipboard.

To retrieve the information on the clipboard, you can call the [OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard) function from another application, which creates a default data object, and the hglobal from the clipboard again becomes a storage object. Furthermore, the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumerator and the [IDataObject::QueryGetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-querygetdata) method would all correctly indicate that the original clipboard format (cfFOO) is again available on a TYMED_ISTORAGE.

To empty the clipboard, call the [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) function specifying a **NULL** value for its parameter. The application should call this when it closes if there is no need to leave data on the clipboard after shutdown, or if data will be placed on the clipboard using the standard Windows clipboard functions.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard)

[OleIsCurrentClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleiscurrentclipboard)

[OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard)