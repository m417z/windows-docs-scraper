# IAutoComplete::Init

## Description

Initializes the autocomplete object.

## Parameters

### `hwndEdit` [in]

Type: **HWND**

A handle to the window for the system edit control for which autocompletion will be enabled.

### `punkACL` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the string list object that generates candidates for the completed string. The object must expose an [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) interface.

### `pwszRegKeyPath` [in, optional]

Type: **LPCWSTR**

A pointer to an optional, null-terminated Unicode string that gives the registry path, including the value name, where the format string is stored as a **REG_SZ** value. The autocomplete object first looks for the path under **HKEY_CURRENT_USER**. If it fails, it tries **HKEY_LOCAL_MACHINE**. For a discussion of the format string, see the definition of *pwszQuickComplete*.

### `pwszQuickComplete` [in, optional]

Type: **LPCWSTR**

A pointer to an optional null-terminated Unicode string that specifies the format to be used if the user enters text and presses CTRL+ENTER. Set this parameter to **NULL** to disable quick completion. Otherwise, the autocomplete object treats *pwszQuickComplete* as a [StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa) format string and the text in the edit box as its associated argument, to produce a new string. For example, set *pwszQuickComplete* to "http://www.%s.com/". When a user enters "MyURL" into the edit box and presses CTRL+ENTER, the text in the edit box is updated to "http://www.MyURL.com/".

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAutoComplete](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-iautocomplete)