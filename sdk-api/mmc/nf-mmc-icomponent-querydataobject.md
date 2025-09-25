# IComponent::QueryDataObject

## Description

The **IComponent::QueryDataObject** method returns a data object that can be used to retrieve context information for the specified cookie.

## Parameters

### `cookie` [in]

A value that specifies the unique identifier for which the data object is required. When called for virtual list items, which do not have cookies, this parameter is set to the item list index.

### `type` [in]

A value that specifies the data object as one of the following.

#### CCT_SCOPE = 0x8000

Data object for the scope item.

#### CCT_RESULT = 0x8001

Data object for the result item.

#### CCT_SNAPIN_MANAGER = 0x8002

Data object for the Snap-In Manager context.

#### CCT_UNINITIALIZED = 0xFFFF

Data object has an invalid type.

These constants are members of the
[DATA_OBJECT_TYPES](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-data_object_types) enumeration.

### `ppDataObject` [out]

A pointer to the address of the returned data object.

## Return value

This method can return one of these values.

## Remarks

These data objects can be passed to the same snap-in or to extension snap-ins that require them. Some of the MMC interfaces that can use this data object are
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent),
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata),
[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider),
[IExtendContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendcontextmenu),
[IExtendPropertySheet2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendpropertysheet2), and
[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider).

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-querydataobject)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)