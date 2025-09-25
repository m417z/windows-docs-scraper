# IAttachmentExecute::SetClientTitle

## Description

Specifies and stores the title of the prompt window.

## Parameters

### `pszTitle` [in]

Type: **LPCWSTR**

A pointer to a string that contains the title text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If **IAttachmentExecute::SetClientTitle** is not called, a default title of **File Download** is used in the prompt's title bar.