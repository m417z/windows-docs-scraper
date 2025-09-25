# SLUnloadApplicationPolicies function

## Description

Releases the policy context handle returned by the [SLLoadApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slloadapplicationpolicies) function.

## Parameters

### `hPolicyContext` [in]

Type: **HSLP**

The context handle returned by the [SLLoadApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slloadapplicationpolicies) function.

### `dwFlags` [in]

Type: **DWORD**

The additional flags.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_APPLICATION_POLICIES_NOT_LOADED**<br><br>0xC004F073 | The policy context was not found. |