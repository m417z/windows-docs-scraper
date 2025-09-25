# INewShortcutHookA::GetReferent

## Description

Gets the referent of the shortcut object.

## Parameters

### `pszReferent`

Type: **PTSTR**

A pointer to a string that receives the referent.

### `cchReferent`

Type: **int**

The size of the buffer at *pszReferent*, in characters.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For Internet shortcut objects, this method is the same as [IUniformResourceLocator::GetURL](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/dd565674(v=vs.85)).