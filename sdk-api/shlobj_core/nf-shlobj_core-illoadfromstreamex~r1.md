# ILLoadFromStreamEx function

## Description

[**ILLoadFromStreamEx(IStream*, PIDLIST_RELATIVE*)**
is available for use in the operating systems specified in the Requirements section. It may be altered or
unavailable in subsequent versions.]

Loads an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) from an
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Parameters

### `pstm`

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface from which the
[ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) loads.

### `ppidl`

Type: **PIDLIST_RELATIVE***

When this method returns and succeeds, contains the resulting relative
[ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist). If it fails, contains
**NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also