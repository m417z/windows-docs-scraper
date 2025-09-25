# ITfKeystrokeMgr::PreserveKey

## Description

Registers a preserved key.

## Parameters

### `tid` [in]

Contains the client identifier of the TSF text service. This value is passed to the TSF text service in its [ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate) method.

### `rguid` [in]

Contains the command GUID of the preserved key. This value is passed to the TSF text service [ITfKeyEventSink::OnPreservedKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeyeventsink-onpreservedkey) method to identify the preserved key when the preserved key is activated.

### `prekey` [in]

Pointer to a [TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey) structure that specifies the preserved key. The **uVKey** member contains the virtual key code and the **uModifiers** member identifies the modifiers of the preserved key.

### `pchDesc` [in]

Pointer to a Unicode string that contains the description of the preserved key. This cannot be **NULL** unless *cchDesc* is zero.

### `cchDesc` [in]

Specifies the number of characters in *pchDesc*. Pass zero for this parameter if no description is required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_ALREADY_EXISTS** | The preserved key is registered. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation error occurred. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Preserved keys are registered by TSF text services and provide keyboard shortcuts to common commands implemented by the TSF text service.

## See also

[ITfKeyEventSink::OnPreservedKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeyeventsink-onpreservedkey)

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[ITfKeystrokeMgr::UnpreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-unpreservekey)

[ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate)

[TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey)