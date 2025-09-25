# ILLoadFromStreamEx function

## Description

[**ILLoadFromStreamEx(IStream*, PITEMID_CHILD*)**
is available for use in the operating systems specified in the Requirements section. It may be altered or
unavailable in subsequent versions.]

Loads a child pointer to an item identifier list (PIDL) from an
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Parameters

### `pstm`

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface from which the child PIDL loads.

### `ppidl`

Type: **PITEMID_CHILD***

When this function returns and succeeds, contains a child PIDL, which contains exactly one **SHITEMID** structure. If it fails, contains **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For use where STRICT_TYPED_ITEMIDS is defined.

## See also