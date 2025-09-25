# SLGetWindowsInformationDWORD function

## Description

Retrieves the **DWORD** value portion of a name-value pair from the licensing policy of a software component.

## Parameters

### `pwszValueName` [in]

A pointer to a null-terminated string that contains the name associated with the value to retrieve.

### `pdwValue` [out]

A pointer to the value associated with the name specified by the *pwszValueName* parameter.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

This function can return the following values defined in Slerror.h.

| Return code/value | Description |
| --- | --- |
| **SL_E_RIGHT_NOT_GRANTED**<br><br>0xC004F013 | The caller does not have the permissions necessary to call this function. |
| **SL_E_DATATYPE_MISMATCHED**<br><br>0xC004F01E | The value portion of the name-value pair is not a **DWORD**. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The requested policy is not defined for the current device. |