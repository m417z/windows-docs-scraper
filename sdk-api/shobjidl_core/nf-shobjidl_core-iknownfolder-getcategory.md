# IKnownFolder::GetCategory

## Description

Retrieves the category—virtual, fixed, common, or per-user—of the selected folder.

## Parameters

### `pCategory` [out]

Type: **[KF_CATEGORY](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category)***

When this method returns, contains a pointer to the [KF_CATEGORY](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category) of the selected folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))