# IDragSourceHelper2::SetFlags

## Description

Sets the characteristics of a drag-and-drop operation over an [IDragSourceHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idragsourcehelper) object.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

The flags that determine the characteristics of a drag-and-drop operation over an [IDragSourceHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idragsourcehelper) object.

#### DSH_ALLOWDROPDESCRIPTIONTEXT (0x0001)

Allow text specified in [DROPDESCRIPTION](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-dropdescription) to be displayed on the drag image. If you pass this flag into the *dwFlags* parameter of **IDragSourceHelper2::SetFlags**, then the text description is rendered on top of the supplied drag image. If you pass a drag image into an [IDragSourceHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idragsourcehelper) object, then by default, the extra text description of the drag-and-drop operation is not displayed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.