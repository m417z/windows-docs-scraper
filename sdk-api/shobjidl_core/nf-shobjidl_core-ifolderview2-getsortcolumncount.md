# IFolderView2::GetSortColumnCount

## Description

Gets the count of sort columns currently applied to the view.

## Parameters

### `pcColumns` [out]

Type: **int***

A pointer to an **int**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Returns E_INVALIDARG if the column count provided does not equal the count of sort columns in the view.