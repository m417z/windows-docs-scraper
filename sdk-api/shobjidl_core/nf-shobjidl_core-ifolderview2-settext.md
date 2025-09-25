# IFolderView2::SetText

## Description

Sets the default text to be used when there are no items in the view.

## Parameters

### `iType` [in]

Type: **FVTEXTTYPE**

This value should be set to the following flag.

#### FVST_EMPTYTEXT

Set the text to display when there are no items in the view.

### `pwszText` [in]

Type: **LPCWSTR**

A pointer to a Unicode string that contains the text to be used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.