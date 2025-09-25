# KsCreateTopologyNode function

## Description

The **KsCreateTopologyNode** function creates a handle to a topology node instance. The function can only be called at **PASSIVE_LEVEL**.

## Parameters

### `ParentHandle` [in]

Specifies the handle to the parent on which the node is created.

### `NodeCreate` [in]

Specifies topology node create parameters.

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) indicating the desired access to the object. This is typically **GENERIC_READ** and/or **GENERIC_WRITE**.

### `NodeHandle` [out]

Location for the topology node handle.

## Return value

Returns **STATUS_SUCCESS**, or an error if unable to create a node.

## Remarks

The [KSNODE_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksnode_create) structure describes the set of information used to create the node handle.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[KSNODE_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksnode_create)