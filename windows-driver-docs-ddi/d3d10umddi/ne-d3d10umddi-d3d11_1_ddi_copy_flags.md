# D3D11_1_DDI_COPY_FLAGS enumeration

## Description

Specifies how to handle the existing contents of a resource during a copy or update operation of a region within that resource. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Constants

### `D3D11_1DDI_COPY_NO_OVERWRITE`

The caller guarantees that the portion of the surface that is being written to with new data is not currently being referenced or accessed by any previous render operation. The driver can take advantage of this capability to optimize performance and memory usage.

### `D3D11_1DDI_COPY_DISCARD`

The user-mode display driver can discard previous contents of the entire resource. The driver can take advantage of this capability to optimize performance and memory usage.

### `D3D11_1DDI_COPY_TILEABLE`

For tile-based deferred rendering, a copy operation can operate on only the currently processed tile in the source or destination resource, and the scene does not have to be flushed in all tiles.