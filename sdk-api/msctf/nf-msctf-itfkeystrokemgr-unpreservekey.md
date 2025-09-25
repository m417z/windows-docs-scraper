# ITfKeystrokeMgr::UnpreserveKey

## Description

Unregisters a preserved key.

## Parameters

### `rguid` [in]

Contains the command GUID of the preserved key.

### `pprekey` [in]

Pointer to a [TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey) structure that specifies the preserved key. The *uVKey* member contains the virtual key code and the *uModifiers* member identifies the modifiers of the preserved key.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **CONNECT_E_NOCONNECTION** | The preserved key is not registered. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

Preserved keys are registered by TSF text services and provide keyboard shortcuts to common commands implemented by the TSF text service.

## See also

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[ITfKeystrokeMgr::PreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-preservekey)

[TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey)