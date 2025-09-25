# SLGetWindowsInformation function

## Description

Retrieves the value portion of a name-value pair from the licensing policy of a software component.

## Parameters

### `pwszValueName` [in]

A pointer to a null-terminated string that contains the name associated with the value to retrieve.

### `peDataType` [out, optional]

A pointer to a value of the [SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype) enumeration that specifies the type of data in the *ppbValue* buffer.

### `pcbValue` [out]

A pointer to the size, in bytes, of the *ppbValue* buffer.

### `ppbValue` [out]

A pointer to an array of **BYTE** pointers that specifies the value associated with the name specified by the *pwszValueName* parameter.

When you have finished using this array, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

This function can return the following values defined in Slerror.h.

| Return code/value | Description |
| --- | --- |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The specified name-value pair was not found. |
| **SL_E_RIGHT_NOT_GRANTED**<br><br>0xC004F013 | The caller does not have the permissions necessary to call this function. |