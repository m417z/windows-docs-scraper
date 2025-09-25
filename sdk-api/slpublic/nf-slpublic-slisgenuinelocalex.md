# SLIsGenuineLocalEx function

## Description

Checks whether the specified application installation is genuine.

## Parameters

### `pAppId` [in]

A pointer to an **SLID** structure that specifies the application to check.

### `pSkuId` [in, optional]

A pointer to an **SLID** structure that specifies the SKU of the application to check.

If this parameter is not **NULL**, this function uses the value of this parameter instead of the value of the *pAppId* parameter to check whether the application installation is genuine. If the SKU license contains a **ProductUniquenessGroupId** value, that value is also used to check whether the application is genuine.

### `pGenuineState` [out]

A pointer to a value of the [SL_GENUINE_STATE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sl_genuine_state) enumeration that specifies the state of the installation. This function does not change the value of this parameter if the return value is any value other than **S_OK**.

If this parameter is **NULL**, the function fails with a return value of **E_INVALIDARG**.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function checks the **Tampered** flag of the license associated with the specified application and the SKU, if specified. If the license is not valid, or if the **Tampered** flag of either license is set, the installation is not considered genuine.