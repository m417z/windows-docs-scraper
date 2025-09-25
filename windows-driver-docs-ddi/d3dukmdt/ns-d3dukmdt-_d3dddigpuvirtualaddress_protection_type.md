# D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE structure

## Description

The **D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE** structure specifies the protection on the GPU virtual address that is mapped.

## Members

### `Write`

The pages will be allowed read-write access.

### `Execute`

The pages will be allowed execute access.

### `Zero`

The pages will be put to the *Zero* state ([**hAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_mapgpuvirtualaddress) must be NULL). Reads return zero and writes are discarded in this state.

### `NoAccess`

The pages will be put to the *Invalid* state ([**hAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_mapgpuvirtualaddress) must be NULL).

### `SystemUseOnly`

This member is for system use only and should not be set by the user-mode driver.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

The consolidated value of the structure's members.

## See also

[**D3DDDI_MAPGPUVIRTUALADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_mapgpuvirtualaddress)