# IAzClientContext2::AddApplicationGroups

## Description

The **AddApplicationGroups** method adds the specified array of existing [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) objects to the client context object.

## Parameters

### `varApplicationGroups` [in]

The array of [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) objects to add.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) objects in the *varApplicationGroups* array must already exist in the authorization store.

The added roles are used in subsequent calls to the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) and [GetRoles](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-getroles) methods.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck)

[GetRoles](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-getroles)

[IAzClientContext2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext2)