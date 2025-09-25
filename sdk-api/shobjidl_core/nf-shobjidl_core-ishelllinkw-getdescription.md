# IShellLinkW::GetDescription

## Description

Gets the description string for a Shell link object.

## Parameters

### `pszName`

Type: **LPTSTR**

A pointer to the buffer that receives the description string.

### `cch`

Type: **int**

The maximum number of characters to copy to the buffer pointed to by the *pszName* parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For Windows 2000 or later, the string returned to *pszName* has a maximum length of INFOTIPSIZE. For systems prior to Windows 2000, the size of the string is limited by MAX_PATH.