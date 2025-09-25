# IActionProgress::UpdateText

## Description

Called if descriptive text associated with the action will be changed.

## Parameters

### `sptext` [in]

Type: **[SPTEXT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sptext)**

A value that specifies the type of text displayed. See [SPTEXT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sptext) for acceptable values.

### `pszText` [in]

Type: **LPCWSTR**

A pointer to a wide character string to display.

### `fMayCompact` [in]

Type: **BOOL**

A value that specifies whether to allow a text string to be compacted to fit the available space on screen.

## Return value

Type: **HRESULT**

Return S_OK if successful, or an error value otherwise.

## Remarks

The class implementing this method must interpret the value of *sptext* and *fMayCompact* in the context of the action being performed and the UI that shows the progress to the user. The value of *sptext* can be used to differentiate between lines of changeable text. Often, the value of *fMayCompact* refers to whether the text string can be truncated with an ellipsis (...) in order to conserve screen space.

## See also

[IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress)

[SPTEXT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sptext)