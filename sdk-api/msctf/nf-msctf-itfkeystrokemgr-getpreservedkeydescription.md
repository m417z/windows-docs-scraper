# ITfKeystrokeMgr::GetPreservedKeyDescription

## Description

Obtains the description string of an existing preserved key.

## Parameters

### `rguid` [in]

Contains the command GUID of the preserved key.

### `pbstrDesc` [out]

Pointer to a BSTR value the receives the description string. The caller must free this memory using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters is invalid or the preserved key is not found. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Preserved keys are registered by TSF text services and provide keyboard shortcuts to common commands implemented by the TSF text service.

## See also

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)