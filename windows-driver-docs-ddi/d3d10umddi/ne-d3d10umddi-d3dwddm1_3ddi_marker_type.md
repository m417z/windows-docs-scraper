# D3DWDDM1_3DDI_MARKER_TYPE enumeration

## Description

Indicates the type of marker that the user-mode display driver supports.

## Constants

### `D3DWDDM1_3DDI_MARKER_TYPE_NONE`

No marker type is supported.

### `D3DWDDM1_3DDI_MARKER_TYPE_PROFILE`

The context submits GPU work for single-threaded user-mode DDIs. In this case, each time stamp denotes the end of GPU work.