# IRegistryKey::DeleteKey

## Description

The `DeleteKey` method deletes the registry key.

## Return value

`DeleteKey` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

A caller deletes an **IRegistryKey** object's registry key by calling the `DeleteKey` method on that object. The key can be deleted only if the caller created the key with an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) that permits deletion. The caller enables deletion by specifying a *DesiredAccess* parameter value of KEY_ALL_ACCESS (described in [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)) to the [PcNewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewregistrykey), [IPort::NewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-newregistrykey), or [IRegistryKey::NewSubKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iregistrykey-newsubkey) call that creates the key. When deleting a key, the **IRegistryKey** object discards its registry-key handle, and all other handles to the deleted key become invalid.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IPort::NewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-newregistrykey)

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[IRegistryKey::NewSubKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iregistrykey-newsubkey)

[PcNewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewregistrykey)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwDeleteKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwdeletekey)