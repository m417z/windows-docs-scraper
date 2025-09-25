# SLGetGenuineInformation function

## Description

Gets information about the genuine state of a Windows computer.

## Parameters

### `pQueryId` [in]

A pointer to an **SLID** structure that specifies the application to check.

### `pwszValueName` [in]

A pointer to a null-terminated string that contains the name associated with the value to retrieve. The following names are valid.

| Value | Meaning |
| --- | --- |
| **SL_BRT_DATA** | Get a value that specifies whether the computer is genuine. |
| **SL_BRT_COMMIT** | Get a value that specifies whether the computer is in nongenuine grace period mode. |
| **SL_GENUINE_RESULT** | Get the value returned from the last call to the [SLAcquireGenuineTicket](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slacquiregenuineticket) function. |
| **SL_NONGENUINE_GRACE_FLAG** | Gets the cause of the computer being put into nongenuine grace period mode. |

### `peDataType` [out, optional]

A pointer to a value of the [SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype) enumeration that specifies the type of data in the *ppbValue* buffer.

### `pcbValue` [out]

A pointer to the size, in bytes, of the *ppbValue* buffer.

### `ppbValue` [out]

The address of a pointer to an array of **BYTE** pointers that specifies the value associated with the name specified by the *pwszValueName* parameter.

When you have finished using this array, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

This function can return the following values defined in Slerror.h.

| Return code/value | Description |
| --- | --- |
| **SL_E_NOT_SUPPORTED**<br><br>0xC004F016 | The name specified by the *pwszValueName* parameter is not supported. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The specified name-value pair was not found. |

## See also

[SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype)

[SLGetWindowsInformation](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgetwindowsinformation)