# IFolderView2::InvokeVerbOnSelection

## Description

Invokes the given verb on the current selection.

## Parameters

### `pszVerb` [in]

Type: **LPCSTR**

A pointer to a Unicode string containing a verb.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *pszVerb* is **NULL**, then the default verb is invoked on the selection.