# ITfThreadMgrEx::GetActiveFlags

## Description

The **ITfThreadMgrEx::GetActiveFlags** method returns the flags TSF is active with.

## Parameters

### `lpdwFlags` [out]

The pointer to the DWORD value to receives the active flags of TSF.

| Value | Meaning |
|:-----------------------------------|:-----------------------------------|
|  **TF_TMF_NOACTIVATETIP** | TSF was activated with the TF_TMAE_NOACTIVATETIP flag. |
|  **TF_TMF_SECUREMODE** | TSF is running as secure mode. |
|  **TF_TMF_UIELEMENTENABLEDONLY** | TSF is running with text services that support only UIElement. |
|  **TF_TMF_COMLESS** | TSF is running without COM. |
|  **TF_TMF_WOW16** | TSF is running in 16bit task. |
|  **TF_TMF_CONSOLE** | TSF is running for console. |
|  **TF_TMF_IMMERSIVEMODE** | **Starting with Windows 8:** TSF is active in a Windows Store app. |
|  **TF_TMF_ACTIVATED** | TSF is active. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |