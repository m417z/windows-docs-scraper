# MI_Instance structure

## Description

This structure represents a CIM instance. This object should not be accessed directly. Instead, the
**MI_Instance_*** functions should be used.

## Members

### `ft`

Pointer to the [MI_InstanceFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instanceft) function table.

### `classDecl`

The class declaration for this instance.

### `serverName`

Optional server name. Can be null.

### `nameSpace`

Optional namespace. Can be null.

### `reserved`

Reserved for internal use.