# IsThemeDialogTextureEnabled function

## Description

Reports whether a specified dialog window supports background texturing.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**HWND** value that specifies a dialog window.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | Background texturing is supported on the dialog window specified by the *hwnd* parameter. |
| **FALSE** | Background texturing is not supported on the dialog window specified by the *hwnd* parameter. |