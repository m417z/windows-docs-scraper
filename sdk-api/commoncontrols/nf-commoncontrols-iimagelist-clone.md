# IImageList::Clone

## Description

Clones an existing image list.

## Parameters

### `riid` [in]

Type: **REFIID**

An IID for the new image list.

### `ppv` [out]

Type: **[PVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The address of a pointer to the interface for the new image list.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::Clone**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).