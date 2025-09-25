# IAzAuthorizationStore3::UpgradeStoresFunctionalLevel

## Description

The **UpgradeStoresFunctionalLevel** method upgrades this authorization store from version 1 to version 2.

## Parameters

### `lFunctionalLevel` [in]

Specifies the version to which to upgrade the authorization store. Set the value of this parameter to **AZ_AZSTORE_NT6_FUNCTION_LEVEL**

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If the authorization store being updated is an Active Directory store, this method checks whether the LDAP schema of the Active Directory store is updated. If the LDAP schema of the Active Directory store is not updated, the authorization store is not updated.