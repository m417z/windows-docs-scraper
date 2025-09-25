# ITfKeystrokeMgr::GetPreservedKey

## Description

Obtains the command GUID for a preserved key.

## Parameters

### `pic` [in]

Pointer to the application context. This value is returned by a previous call to [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext).

### `pprekey` [in]

Pointer to a [TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey) structure that identifies the preserved key to obtain. The **uVKey** member contains the virtual key code and the **uModifiers** member identifies the modifiers of the preserved key. The **uVKey** member must be less than 256.

### `pguid` [out]

Pointer to a GUID value that receives the command GUID of the preserved key. This is the GUID passed in the TSF text service call to [ITfKeystrokeMgr::PreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-preservekey). This value receives GUID_NULL if the preserved key is not found.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful and the preserved key was found. |
| **S_FALSE** | The method was successful, but the preserved key was not found. *pguid* receives GUID_NULL. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Preserved keys are registered by TSF text services and used to provide keyboard shortcuts to common commands implemented by the TSF text service.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[ITfKeystrokeMgr::PreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-preservekey)

[TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey)