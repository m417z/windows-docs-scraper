# D3DDDIARG_COPYFLAGS structure

## Description

Describes how to handle the existing contents of a resource during a copy or update operation of a region within that resource. Used by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Members

### `NoOverwrite`

Specifies that the caller guarantees that the portion of the surface that is being written to with new data is not currently being referenced or accessed by any previous render operation. The driver can take advantage of this capability to optimize performance and memory usage.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Discard`

Specifies that the user-mode display driver can discard previous contents of the entire resource. The driver can take advantage of this capability to optimize performance and memory usage.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Reserved1`

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting bits 3 through 24 (0x00FFFFFC) of the 32-bit **Value** member to zeros.

### `BoxValid`

Specifies that a destination region of the subresource to be copied to is valid. When not set, the entire subresource must be updated.

Setting this member is equivalent to setting the twenty-fifth bit of the 32-bit **Value** member (0x01000000).

### `Reserved2`

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting bits 26 through 32 (0xFE000000) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that **D3DDDIARG_COPYFLAGS** contains that can hold a 32-bit value that identifies how to handle the existing contents of a resource during a copy or update operation.

## See also

[D3DDDIARG_UPDATESUBRESOURCEUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_updatesubresourceup)