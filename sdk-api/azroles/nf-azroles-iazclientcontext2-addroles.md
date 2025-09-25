# IAzClientContext2::AddRoles

## Description

The **AddRoles** method adds the specified array of existing [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) objects to the client context.

## Parameters

### `varRoles` [in]

The array of role names that specify the [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) objects to add to the client context.

### `bstrScopeName` [in]

The scope to which the array of roles applies.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) objects associated with the names in the *varRoles* array must already exist in the specified scope.

The added roles are used in subsequent calls to the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) and [GetRoles](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-getroles) methods.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck)

[GetRoles](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-getroles)

[IAzClientContext2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext2)