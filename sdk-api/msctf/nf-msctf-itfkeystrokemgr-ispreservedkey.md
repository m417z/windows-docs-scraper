# ITfKeystrokeMgr::IsPreservedKey

## Description

Determines if a command GUID and key combination is a preserved key.

## Parameters

### `rguid` [in]

Specifies the command GUID of the preserved key. This is the GUID passed in the text service call to [ITfKeystrokeMgr::PreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-preservekey).

### `pprekey` [in]

Pointer to a [TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey) structure that identifies the preserved key. The **uVKey** member contains the virtual key code and the **uModifiers** member identifies the modifiers of the preserved key. The **uVKey** member must be less than 256.

### `pfRegistered` [out]

Pointer to a BOOL that receives **TRUE** if the command GUID and key combination is a registered preserved key, or **FALSE** otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful and the preserved key was found. |
| **S_FALSE** | The method was successful, but the preserved key was not found. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Preserved keys are registered by TSF text services and provide keyboard shortcuts to common commands implemented by the TSF text service.

## See also

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[ITfKeystrokeMgr::PreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-preservekey)

[TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey)