# IBrowserService::GetSetCodePage

## Description

Deprecated. Sets a new character code page and retrieves a pointer to the previous code page.

## Parameters

### `pvarIn` [in]

Type: **VARIANT***

A pointer to a **VARIANT** that represents the new character code page. Only VT_I4 is supported. This parameter can be **NULL**.

### `pvarOut` [out]

Type: **VARIANT***

A pointer to a **VARIANT** that represents the previous character code page. Only VT_I4 is supported. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.