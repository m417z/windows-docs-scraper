# SLSetGenuineInformation function

## Description

Specifies information about the genuine status of a Windows computer.

## Parameters

### `pQueryId` [in]

A pointer to an **SLID** structure that specifies the application for which to set information.

### `pwszValueName` [in]

A pointer to a null-terminated string that contains the name associated with the value to set. The following names are valid.

| Value | Meaning |
| --- | --- |
| **SL_BRT_DATA** | Set information about the genuine state of the computer. |
| **SL_BRT_COMMIT** | If the **SL_BRT_DATA** value is set, setting **SL_BRT_COMMIT** puts the computer in nongenuine grace period mode. |

### `eDataType` [in]

A pointer to a value of the [SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype) enumeration that specifies the type of data in the *pbValue* buffer.

### `cbValue` [in, optional]

A pointer to the size, in bytes, of the *pbValue* buffer.

### `pbValue` [in, optional]

A pointer to an array of **BYTE** values that specify the value associated with the name specified by the *pwszValueName* parameter.

Some name-value pairs allow this parameter to be **NULL**. In this case, the existing value of the name-value pair is deleted.

When you have finished using this array, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

This function can return the following values defined in Winerror.h and Slerror.h.

| Return code/value | Description |
| --- | --- |
| **E_ACCESS_DENIED**<br><br>0x80070005 | The caller does not have administrative privileges. |
| **E_INVALIDARG**<br><br>0x80000003 | The *pbValue* parameter cannot be **NULL**. |
| **(HRESULT_FROM_WIN32)ERROR_BUFFER_OVERFLOW**<br><br>0x111 | The *pbValue* buffer is too small to hold the data. |
| **SL_E_DATATYPE_MISMATCHED**<br><br>0xC004F01E | The data type of the *pbValue* parameter does not match the type specified by the *eDataType* parameter. |
| **SL_E_DEPENDENT_PROPERTY_NOT_SET**<br><br>0xC004F066 | The specified name-value pair is dependent on a name-value pair that has not been set. |
| **SL_E_NOT_SUPPORTED**<br><br>0xC004F016 | The name specified by the *pwszValueName* parameter is not supported. |