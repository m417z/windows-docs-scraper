# IKsTopology::CreateNodeInstance

## Description

The **CreateNodeInstance** method requests a KS filter object to open a topology node object.

## Parameters

### `NodeId` [in]

Identifier for the topology node object to open.

### `Flags` [in]

A bitmask enumerating the type of topology node object. No flags are currently defined.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) bitmask specifying the type of access that the caller requires to the topology node object. See [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) for a description of each access-right value.

### `UnkOuter` [in, optional]

Pointer to an **IUnknown** interface that supports the topology node interface.

### `InterfaceId` [in]

Identifier of the topology node interface being requested.

### `Interface` [out]

Pointer to a variable that receives the interface pointer requested in *InterfaceId*. Upon successful return, **Interface* contains the requested interface pointer to the object. If the object does not support the interface specified in *InterfaceId*, **Interface* is set to **NULL**.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IKsTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikstopology)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)