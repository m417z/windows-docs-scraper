# IImageList::GetDragImage

## Description

Gets the temporary image list that is used for the drag image. The function also retrieves the current drag position and the offset of the drag image relative to the drag position.

## Parameters

### `ppt` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the current drag position. Can be **NULL**.

### `pptHotspot` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the offset of the drag image relative to the drag position. Can be **NULL**.

### `riid` [out]

Type: **REFIID**

An IID for the image list.

### `ppv` [out]

Type: **[PVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The address of a pointer to the interface for the image list if successful, **NULL** otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The temporary image list is destroyed when [IImageList::EndDrag](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-enddrag) is called. To begin a drag operation, use [IImageList::BeginDrag](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-begindrag).

To use **IImageList::GetDragImage**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).