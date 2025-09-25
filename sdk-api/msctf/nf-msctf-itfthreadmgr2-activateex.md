# ITfThreadMgr2::ActivateEx

## Description

Initializes and activates TSF for the calling thread with a flag that specifies how TSF is activated.

## Parameters

### `ptid` [out]

[out] Pointer to a [TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid) value that receives a client identifier.

### `dwFlags` [in]

| Value | Meaning |
| --- | --- |
| **TF_TMAE_NOACTIVATETIP** | Text services will not be activated while this method is called. They will be activated when the calling thread has focus asynchronously. |
| **TF_TMAE_SECUREMODE** | TSF is activated in secure mode. Only text services that support the secure mode will be activated. |
| **TF_TMAE_UIELEMENTENABLEDONLY** | TSF activates only text services that are categorized in GUID_TFCAT_TIPCAP_UIELEMENTENABLED. |
| **TF_TMAE_COMLESS** | TSF does not use COM. TSF activate only text services that are categorized in GUID_TFCAT_TIPCAP_COMLESS. |
| **TF_TMAE_NOACTIVATEKEYBOARDLAYOUT** | TSF does not sync the current keyboard layout while this method is called. The keyboard layout will be adjusted when the calling thread gets focus. This flag must be used with TF_TMAE_NOACTIVATETIP. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITfThreadMgr2](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr2)