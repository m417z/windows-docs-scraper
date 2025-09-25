# IShellItem::BindToHandler

## Description

Binds to a handler for an item as specified by the handler ID value (BHID).

## Parameters

### `pbc`

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object. Used to pass optional parameters to the handler. The contents of the bind context are handler-specific. For example, when binding to **BHID_Stream**, the [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) flags in the bind context indicate the mode of access desired (read or read/write).

### `bhid`

Type: **REFGUID**

Reference to a GUID that specifies which handler will be created. One of the following values defined in Shlguid.h:

#### BHID_SFObject

Restricts usage to [BindToObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-bindtoobject).

#### BHID_SFUIObject

Restricts usage to [GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof).

#### BHID_SFViewObject

Restricts usage to [CreateViewObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-createviewobject).

#### BHID_Storage

Attempts to retrieve the storage RIID, but defaults to Shell implementation on failure.

#### BHID_Stream

Restricts usage to [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

#### BHID_LinkTargetItem

CLSID_ShellItem is initialized with the target of this item (can only be SFGAO_LINK). See [SFGAO](https://learn.microsoft.com/windows/win32/shell/sfgao) for a description of SFGAO_LINK.

#### BHID_StorageEnum

If the item is a folder, gets an [IEnumShellItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumshellitems) object with which to enumerate the storage contents.

#### BHID_Transfer

**Introduced in Windows Vista**: If the item is a folder, gets an [ITransferSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransfersource) or [ITransferDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransferdestination) object.

#### BHID_PropertyStore

**Introduced in Windows Vista**: Restricts usage to [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorefactory).

#### BHID_ThumbnailHandler

**Introduced in Windows Vista**: Restricts usage to [IExtractImage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iextractimage) or [IThumbnailProvider](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-ithumbnailprovider).

#### BHID_EnumItems

**Introduced in Windows Vista**: If the item is a folder, gets an [IEnumShellItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumshellitems) object that enumerates all items in the folder. This includes folders, nonfolders, and hidden items.

#### BHID_DataObject

**Introduced in Windows Vista**: Gets an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object for use with an item or an array of items.

#### BHID_AssociationArray

**Introduced in Windows Vista**: Gets an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) object for use with an item or an array of items.

#### BHID_Filter

**Introduced in Windows Vista**: Restricts usage to [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter).

#### BHID_EnumAssocHandlers

**Introduced in Windows 7**: Gets an [IEnumAssocHandlers](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumassochandlers) object used to enumerate the recommended association handlers for the given item.

#### BHID_RandomAccessStream

**Introduced in Windows 8**: Gets an [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)) object for the item.

#### BHID_FilePlaceholder

**Introduced in Windows 8.1**: Gets an object used to provide placeholder file functionality.

### `riid`

Type: **REFIID**

IID of the object type to retrieve.

### `ppv`

Type: **void****

When this method returns, contains a pointer of type *riid* that is returned by the handler specified by *rbhid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)