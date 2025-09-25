# ICertRequest2::GetErrorMessageText

## Description

The **GetErrorMessageText** method retrieves the error message text for an **HRESULT** error code.

 If the error message text is localized, it has been localized on the client.

## Parameters

### `hrMessage` [in]

A value that represents an **HRESULT** error.

### `Flags` [in]

A **LONG** value that corresponds to one of the values in the following table.

| Value | Meaning |
| --- | --- |
| **Zero (0)** | The error message text will not have the **HRESULT** hexadecimal and decimal values appended. |
| **CR_GEMT_HRESULT_STRING** | The error message text will have the **HRESULT** hexadecimal and decimal values appended. |

### `pstrErrorMessageText` [out]

A pointer to the **BSTR** that represents the error message text for *hrMessage*. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** that contains the error message text for *hrMessage*.