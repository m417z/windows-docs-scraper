# ILLoadFromStreamEx function

## Description

[**ILLoadFromStreamEx(IStream*, PIDLIST_ABSOLUTE*)**
is available for use in the operating systems specified in the Requirements section. It may be altered or
unavailable in subsequent versions.]

Loads an absolute [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) from an
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface from which the absolute
[ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) loads.

### `pidl` [out]

Type: **PIDLIST_ABSOLUTE***

When this method returns and succeeds, contains the resulting absolute
[ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist). If it fails, contains
**NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For use where STRICT_TYPED_ITEMIDS is defined.