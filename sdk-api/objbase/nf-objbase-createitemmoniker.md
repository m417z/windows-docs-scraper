# CreateItemMoniker function

## Description

Creates an item moniker that identifies an object within a containing object (typically a compound document).

## Parameters

### `lpszDelim` [in]

A pointer to a wide character string (two bytes per character) zero-terminated string containing the delimiter (typically "!") used to separate this item's display name from the display name of its containing object.

### `lpszItem` [in]

A pointer to a zero-terminated string indicating the containing object's name for the object being identified. This name can later be used to retrieve a pointer to the object in a call to [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject).

### `ppmk` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the item moniker. When successful, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the item moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the supplied interface pointer has a **NULL** value.

## Return value

This function can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

A moniker provider, which hands out monikers to identify its objects so they are accessible to other parties, would call **CreateItemMoniker** to identify its objects with item monikers. Item monikers are based on a string, and identify objects that are contained within another object and can be individually identified using a string. The containing object must also implement the [IOleContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecontainer) interface.

Most moniker providers are OLE applications that support linking. Applications that support linking to objects smaller than file-based documents, such as a server application that allows linking to a selection within a document, should use item monikers to identify the objects. Container applications that allow linking to embedded objects use item monikers to identify the embedded objects.

The *lpszItem* parameter is the name used by the document to uniquely identify the object. For example, if the object being identified is a cell range in a spreadsheet, an appropriate name might be something like "A1:E7." An appropriate name when the object being identified is an embedded object might be something like "embedobj1." The containing object must provide an implementation of the [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface that can interpret this name and locate the corresponding object. This allows the item moniker to be bound to the object it identifies.

Item monikers are not used in isolation. They must be composed with a moniker that identifies the containing object as well. For example, if the object being identified is a cell range contained in a file-based document, the item moniker identifying that object must be composed with the file moniker identifying that document, resulting in a composite moniker that is the equivalent of "C:\work\sales.xls!A1:E7."

Nested containers are allowed also, as in the case where an object is contained within an embedded object inside another document. The complete moniker of such an object would be the equivalent of "C:\work\report.doc!embedobj1!A1:E7." In this case, each containing object must call **CreateItemMoniker** and provide its own implementation of the [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IMoniker::ComposeWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-composewith)

[IOleContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecontainer)

[IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer)