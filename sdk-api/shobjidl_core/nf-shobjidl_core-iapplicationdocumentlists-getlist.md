# IApplicationDocumentLists::GetList

## Description

Retrieves an object that represents the collection of destinations listed in the **Recent** or **Frequent** category in a Jump List.

## Parameters

### `listtype` [in]

Type: **APPDOCLISTTYPE**

One of the following values that specifies from which category the list of destinations should be retrieved.

#### ADLT_RECENT (0x0)

0x0. The **Recent** category, which lists those items most recently accessed.

#### ADLT_FREQUENT (0x1)

0x1. The **Frequent** category, which lists the items that have been accessed the greatest number of times.

### `cItemsDesired` [in]

Type: **UINT**

The number of items to retrieve from the list specified in *listtype*. Set this parameter to 0 to retrieve the full list.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IObjectArray or IID_IEnumObjects.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically an [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray) or [IEnumObjects](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumobjects) which represents a collection of [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) objects (or a mix of the two) that represent the retrieved items from the list.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An item can appear in both the **Recent** and **Frequent** lists.

If a user pins an item in the **Recent** or **Frequent** categories, the item is no longer shown in its original category to avoid duplication in the Jump List. However, the item will still be returned by this method.

## See also

[IApplicationDocumentLists](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdocumentlists)

[IApplicationDocumentLists::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdocumentlists-setappid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)