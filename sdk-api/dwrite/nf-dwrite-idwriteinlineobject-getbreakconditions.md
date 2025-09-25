# IDWriteInlineObject::GetBreakConditions

## Description

 Layout uses this to determine the line-breaking behavior of the inline object
among the text.

## Parameters

### `breakConditionBefore` [out]

Type: **[DWRITE_BREAK_CONDITION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_break_condition)***

When this method returns, contains a value which indicates the line-breaking condition between the object and the content immediately preceding it.

### `breakConditionAfter` [out]

Type: **[DWRITE_BREAK_CONDITION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_break_condition)***

When this method returns, contains a value which indicates the line-breaking condition between the object and the content immediately following it.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)