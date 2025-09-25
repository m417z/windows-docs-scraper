# D3DDDI_COPY_FLAGS enumeration

## Description

Specifies how to handle the existing contents of a resource during a copy or update operation of a region within that resource.

## Constants

### `D3DDDI_COPY_NO_OVERWRITE`

The caller guarantees that the portion of the surface that is being written to with new data is not currently being referenced or accessed by any previous render operation. The driver can take advantage of this capability to optimize performance and memory usage.

### `D3DDDI_COPY_DISCARD`

The user-mode display driver can discard previous contents of the entire resource. The driver can take advantage of this capability to optimize performance and memory usage.