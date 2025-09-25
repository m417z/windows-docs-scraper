# IAccessControl::GetAllAccessRights

## Description

Gets the entire list of access rights and/or the owner and group for the specified object.

## Parameters

### `lpProperty` [in]

The name of the property. If you are using the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this parameter must be **NULL**.

### `ppAccessList` [out]

The address of the pointer variable that receives a pointer to the access list structure. This parameter cannot be [ACTRL_ACCESS](https://learn.microsoft.com/windows/win32/api/accctrl/ns-accctrl-explicit_access_a).

If the call succeeds, the caller must free the allocated memory with the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function. Note that the memory is allocate(all_nodes), which means that all the substructures are allocated in one block. Therefore, the entire data structure must be freed by a single call to **CoTaskMemFree**.

### `ppOwner` [out]

A pointer to a [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that receives the owner information. If this parameter is not **NULL** and the function succeeds, the caller must free the memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `ppGroup` [out]

A pointer to a [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that receives the group information. If this parameter is not **NULL** and the function succeeds, the caller must free the memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ACTRL_ACCESS](https://learn.microsoft.com/windows/win32/api/accctrl/ns-accctrl-explicit_access_a)

[IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol)