# OleCreateLinkFromData function

## Description

Creates a linked object from a data transfer object retrieved either from the clipboard or as part of an OLE drag-and-drop operation.

## Parameters

### `pSrcDataObj` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data transfer object from which the linked object is to be created.

### `riid` [in]

Reference to the identifier of interface the caller later uses to communicate with the new object (usually IID_IOleObject, defined in the OLE headers as the interface identifier for [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)).

### `renderopt` [in]

Value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) that indicates the locally cached drawing or data-retrieval capabilities the newly created object is to have. Additional considerations are described in the following Remarks section.

### `pFormatEtc` [in]

 Pointer to a value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) that indicates the locally cached drawing or data-retrieval capabilities the newly created object is to have. The **OLERENDER** value chosen affects the possible values for the *pFormatEtc* parameter.

### `pClientSite` [in]

 Pointer to an instance of [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite), the primary interface through which the object will request services from its container. This parameter can be **NULL**.

### `pStg` [in]

Pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object. This parameter cannot be **NULL**.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, *ppvObj* contains the requested interface pointer on the newly created object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **CLIPBRD_E_CANT_OPEN** | Not able to open the clipboard. |
| **OLE_E_CANT_GETMONIKER** | Not able to extract the object's moniker. |
| **OLE_E_CANT_BINDTOSOURCE** | Not able to bind to source. Binding is necessary to get the cache's initialization data. |

## Remarks

The **OleCreateLinkFromData** function is used to implement either a paste-link or a drag-link operation. Its operation is similar to that of the [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) function, except that it creates a link, and looks for different data formats. If the CF_LINKSOURCE format is not present, and either the FileName or FileNameW clipboard format is present in the data transfer object, **OleCreateLinkFromData** creates a package containing the link to the indicated file.

You use the renderopt and *pFormatetc* parameters to control the caching capability of the newly created object. For general information on how to determine what is to be cached, refer to the [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) enumeration for a description of the interaction between renderopt and *pFormatetc*. There are, however, some additional specific effects of these parameters on the way **OleCreateLinkFromData** initializes the cache, as follows.

| Value | Description |
| --- | --- |
| OLERENDER_DRAW, OLERENDER_FORMAT | If the presentation information is in the other formats in the source data object, this information is used. If the information is not present, the cache is initially empty, but will be filled the first time the object is run. No other formats are cached in the newly created object. |
| OLERENDER_NONE, OLERENDER_ASIS | Nothing is to be cached in the newly created object. |

## See also

[OleCreateLink](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelink)