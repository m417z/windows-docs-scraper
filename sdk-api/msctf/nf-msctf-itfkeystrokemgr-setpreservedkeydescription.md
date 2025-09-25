# ITfKeystrokeMgr::SetPreservedKeyDescription

## Description

Modifies the description string of an existing preserved key.

## Parameters

### `rguid` [in]

Contains the command GUID of the preserved key.

### `pchDesc` [in]

Pointer to a Unicode string that contains the new description of the preserved key. This cannot be **NULL** unless *cchDesc* is zero.

### `cchDesc` [in]

Number of characters in *pchDesc*. Pass zero for this parameter if no description is required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid or the preserved key is not found. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Preserved keys are registered by TSF text services and provide keyboard shortcuts to common commands implemented by the TSF text service.

## See also

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[ITfKeystrokeMgr::GetPreservedKeyDescription](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-getpreservedkeydescription)