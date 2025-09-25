# SLQueryLicenseValueFromApp function

## Description

[This API is not available to all Windows/Windows Phone apps. Unless your developer account is specially provisioned by Microsoft, calls to these APIs will fail at runtime.]

Gets the value for the specified component policy.

## Parameters

### `valueName` [in]

The name of the policy for which you want to get information.

### `valueType` [out, optional]

The data type of the policy value. The following table describes the values that this parameter can
receive.

| Value | Description |
| --- | --- |
| REG_DWORD | A 32-bit integer. For this type, the size of the buffer that the *dataBuffer* parameter specifies should be at least 4 bytes. |
| REG_BINARY | A binary value. |
| REG_SZ | A wide-character, null-terminated string, including the last null character. |

### `dataBuffer` [out, optional]

A buffer that receives the value of the component policy.

### `dataSize` [in]

The size of the supplied buffer, in bytes.

### `resultDataSize` [out]

The actual size of the data received for the policy value, in bytes.

## Return value

If this function succeeds, it return **S_OK**. Otherwise, it returns an
**HRESULT** error code.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The specified name-value pair was not found. |

## Remarks

Your app must have the restricted slapiQueryLicenseValue capability to call the **SLQueryLicenseValueFromApp** function.