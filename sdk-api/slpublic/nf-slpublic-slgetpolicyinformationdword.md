# SLGetPolicyInformationDWORD function

## Description

Gets the policy information after right has been consumed successfully.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pwszValueName` [in]

Type: **PCWSTR**

The policy name.

### `pdwValue` [out]

Type: **DWORD***

A pointer to the return value.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The value for the input key was not found. |
| **SL_E_RIGHT_NOT_GRANTED**<br><br>0xC004F013 | The caller does not have permission to run the software. |
| **SL_E_DATATYPE_MISMATCHED**<br><br>0xC004F01E | The input data type does not match the data type in the license. |