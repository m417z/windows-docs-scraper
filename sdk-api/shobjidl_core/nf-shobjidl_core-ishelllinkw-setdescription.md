# IShellLinkW::SetDescription

## Description

Sets the description for a Shell link object. The description can be any application-defined string.

## Parameters

### `pszName`

Type: **LPCTSTR**

A pointer to a buffer containing the new description string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For Windows 2000 or later, the string specified by *pszName* must be no larger than INFOTIPSIZE. For systems prior to Windows 2000, the size of the string is limited by MAX_PATH.