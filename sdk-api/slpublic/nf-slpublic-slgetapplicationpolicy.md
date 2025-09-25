# SLGetApplicationPolicy function

## Description

Queries a policy from the set stored with the [SLPersistApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slpersistapplicationpolicies) function
and loaded using the [SLLoadApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slloadapplicationpolicies) function.

## Parameters

### `hPolicyContext` [in]

Type: **HSLP**

The context handle returned by the [SLLoadApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slloadapplicationpolicies) function.

### `pwszValueName` [in]

Type: **PCWSTR**

The name of the policy to query, or "*" for all policies.

### `peDataType` [out, optional]

Type: **[SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype)***

A pointer to the type of the data, if available.

### `pcbValue` [out]

Type: **UINT***

A pointer to the size, in bytes, of the data, if available.

### `ppbValue` [out]

Type: **PBYTE***

 The data, if available.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_APPLICATION_POLICIES_NOT_LOADED**<br><br>0xC004F073 | The policy context was not found. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The policy is not found. |
| **SL_E_RIGHT_NOT_GRANTED**<br><br>0xC004F013 | The policy list is empty. |