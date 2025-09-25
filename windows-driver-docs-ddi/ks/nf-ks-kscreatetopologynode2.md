# KsCreateTopologyNode2 function

## Description

Creates a handle to a topology node instance.

Supported starting in Windows 8.

## Parameters

### `ParentHandle` [in]

Specifies the handle to the parent on which the node is created.

### `NodeCreate` [in]

A [KSNODE_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksnode_create) structure that describes the set of information that is used to create the topology node handle.

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) indicating the desired access to the object. This is typically **GENERIC_READ** and/or **GENERIC_WRITE**.

### `NodeHandle` [out]

Location for the topology node handle.

## Return value

Returns **NOERROR** if successful; otherwise, returns an error code.

## Remarks

This is a new version of the [KsCreateTopologyNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatetopologynode) function and uses the device broker to create the handle to the kernel streaming object. In addition, the Component Object Model (COM) [CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize) function must be called before this function is called.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize)

[KSNODE_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksnode_create)

[KsCreateTopologyNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatetopologynode)