# SHGetItemFromDataObject function

## Description

Creates an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or related object based on an item specified by an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject).

## Parameters

### `pdtobj` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to the source [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) instance.

### `dwFlags` [in]

Type: **[DATAOBJ_GET_ITEM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-dataobj_get_item_flags)**

One or more values from the [DATAOBJ_GET_ITEM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-dataobj_get_item_flags) enumeration to specify options regarding the target object. This value can be 0.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IShellItem.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.