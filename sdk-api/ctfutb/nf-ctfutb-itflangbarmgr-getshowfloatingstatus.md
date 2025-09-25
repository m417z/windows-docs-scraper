# ITfLangBarMgr::GetShowFloatingStatus

## Description

Obtains current language bar display settings.

## Parameters

### `pdwFlags` [out]

Indicates current language bar display settings. For a list of bitfield values, see [ITfLangBarMgr::ShowFloating](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbarmgr-showfloating).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pdwFlags* is invalid. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfLangBarMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbarmgr)

[ITfLangBarMgr::ShowFloating](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbarmgr-showfloating)