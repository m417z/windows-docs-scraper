# ITextRange2::SetActiveSubrange

## Description

Makes the specified subrange the active subrange of this range.

## Parameters

### `cpAnchor` [in]

Type: **long**

The anchor end character position of the subrange to make active.

### `cpActive` [in]

Type: **long**

The active end character position of the subrange to make active.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The active subrange is the one affected by operations such as Shift+Arrow keys if this range is the selection.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)