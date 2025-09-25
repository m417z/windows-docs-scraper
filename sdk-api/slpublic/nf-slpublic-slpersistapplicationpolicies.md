# SLPersistApplicationPolicies function

## Description

Stores the current consumed policies to disk for fast policy access.

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

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |

## Remarks

If the internal consumption fails then any current cache data is deleted.
Subsequent calls to the [SLLoadApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slloadapplicationpolicies) function will return
**SL_E_APPLICATION_POLICIES_MISSING**.

The **SLPersistApplicationPolicies** function returns success if the policy update succeeds,
regardless of internal consumption results.