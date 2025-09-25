# IVisualProperties::SetTheme

## Description

Sets the specified theme.

## Parameters

### `pszSubAppName` [in]

Type: **LPCWSTR**

A pointer to a Unicode string that contains the application name to use in place of the calling application's name. If this parameter is **NULL**, the calling application's name is used.

### `pszSubIdList` [in]

Type: **LPCWSTR**

A pointer to a Unicode string that contains a semicolon-separated list of CLSID names for use in place of the actual list passed by the window's class. If this parameter is **NULL**, the ID list from the calling class is used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.