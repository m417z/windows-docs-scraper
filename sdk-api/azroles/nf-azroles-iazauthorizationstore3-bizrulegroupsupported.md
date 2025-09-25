# IAzAuthorizationStore3::BizruleGroupSupported

## Description

The **BizruleGroupSupported** method returns a Boolean value that specifies whether this [IAzAuthorizationStore3](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore3) object supports application groups that use business rule (BizRule) scripts.

## Parameters

### `pbSupported` [out]

**VARIANT_TRUE** if the current [IAzAuthorizationStore3](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore3) object supports scripts that use business logic to determine group membership; otherwise, **VARIANT_FALSE**.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).