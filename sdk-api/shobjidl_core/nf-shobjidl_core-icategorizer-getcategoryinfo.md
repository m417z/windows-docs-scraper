# ICategorizer::GetCategoryInfo

## Description

Gets information about a category, such as the default display and the text to display in the UI.

## Parameters

### `dwCategoryId` [in]

Type: **DWORD**

A **DWORD** that specifies a category identifier.

### `pci` [out]

Type: **[CATEGORY_INFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-category_info)***

When this method returns, contains a pointer to a [CATEGORY_INFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-category_info) structure that contains the category information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.