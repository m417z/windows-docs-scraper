# IAzAuthorizationStore3::IsFunctionalLevelUpgradeSupported

## Description

The **IsFunctionalLevelUpgradeSupported** method gets a Boolean value that indicates whether the version of this authorization store can be upgraded.

## Parameters

### `lFunctionalLevel` [in]

The version to check. Set this parameter to **AZ_AZSTORE_NT6_FUNCTION_LEVEL**.

### `pbSupported` [out]

**VARIANT_TRUE** if the underlying authorization store supports version 2 functionality; otherwise, **VARIANT_FALSE**.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IAzAuthorizationStore3](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore3)

[UpgradeStoresFunctionalLevel](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore3-upgradestoresfunctionallevel)