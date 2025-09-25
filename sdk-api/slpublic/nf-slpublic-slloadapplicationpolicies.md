# SLLoadApplicationPolicies function

## Description

Loads the application policies set with the [SLPersistApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slpersistapplicationpolicies) function
for use by the [SLGetApplicationPolicy](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgetapplicationpolicy) function.

## Parameters

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the identifier of the application ID to be used for the fast policy queries.

### `pProductSkuId` [in, optional]

Type: **const SLID***

A pointer to the identifier of the ACID to be used for the fast policy queries.

### `dwFlags` [in]

Type: **DWORD**

Additional flags.

### `phPolicyContext` [out]

Type: **HSLP***

A pointer to a policy context for use in the [SLGetApplicationPolicy](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgetapplicationpolicy) function and
the [SLUnloadApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slunloadapplicationpolicies) function.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_APPLICATION_POLICIES_MISSING**<br><br>0xC004F072 | The license policies for fast query could not be found. |