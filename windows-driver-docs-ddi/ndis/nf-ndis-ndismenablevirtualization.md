# NdisMEnableVirtualization function

## Description

A miniport driver calls the **NdisMEnableVirtualization** function during the creation or deletion of a NIC switch on the network adapter. By calling this function, the driver configures the single root I/O virtualization (SR-IOV) Extended Capability structure in the PCI Express (PCIe) configuration space for the network adapter's Physical Function (PF).

**Note** **NdisMEnableVirtualization** must only be called by the miniport driver for the network adapter's PF.

## Parameters

### `NdisMiniportHandle` [in]

The network adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `NumVFs` [in]

A USHORT value that contains the number of Virtual Functions (VFs) that are to be enabled for the network adapter. **NdisMEnableVirtualization** sets the **NumVFs** member of the SR-IOV Extended Capability structure to the value of the *NumVFs* parameter.

**Note** If the *EnableVirtualization* parameter is FALSE, *NumVFs* must be set to zero.

### `EnableVFMigration` [in]

 This parameter is reserved for NDIS and must be set to FALSE.

### `EnableMigrationInterrupt` [in]

 This parameter is reserved for NDIS and must be set to FALSE.

### `EnableVirtualization` [in]

A BOOLEAN value that specifies whether virtualization should be enabled in the PCI configuration space of the network adapter. If *EnableVirtualization* is TRUE, **NdisMEnableVirtualization** sets the **VF Enable** bit of the SR-IOV Control member. **NdisMEnableVirtualization** clears this bit if *EnableVirtualization* is FALSE.

## Return value

**NdisMEnableVirtualization** can return one of the following status values.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The virtualization operation completed successfully. |
| **NDIS_STATUS_NOT_SUPPORTED** | The adapter or system does not support SR-IOV. |
| **NDIS_STATUS_INVALID_PARAMETER** | The *EnableVirtualization* parameter is set to FALSE and the *NumVFs* parameter is set to a nonzero value. |
| **NDIS_STATUS_FAILURE** | The virtualization operation failed.<br><br>**Note** The **NdisMEnableVirtualization** function fails if it is called to enable virtualization when virtualization is already enabled. The driver must first disable virtualization (by calling the function with the **EnableVirtualization** parameter set to FALSE) before the driver can reenable virtualization. |

## Remarks

PF miniport drivers call **NdisMEnableVirtualization** to configure the SR-IOV Extended Capability fields in the PCI configuration space. This call is used to enable or disable virtualization in the configuration space, and also to specify the number of VFs that should be exposed to the PCIe fabric by the network adapter.

When the PF miniport driver handles an OID method request of [OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch), the driver calls **NdisMEnableVirtualization** to enable virtualization on the network adapter for the NIC switch. The driver does this by calling **NdisMEnableVirtualization** with the following parameter settings.

| Term | Description |
| --- | --- |
| *NumVFs* | Set to the number of VFs to be enabled for the NIC switch. |
| *EnableVirtualization* | Set to TRUE. |

When the PF miniport driver handles an OID method request of [OID_NIC_SWITCH_DELETE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-delete-switch), the driver calls **NdisMEnableVirtualization** to disable virtualization on the network adapter. The driver does this by calling **NdisMEnableVirtualization** with the following parameter settings:

| Term | Description |
| --- | --- |
| *NumVFs* | Set to zero. |
| *EnableVirtualization* | Set to FALSE. |

For more information on how to create a NIC switch, see [Creating a NIC Switch](https://learn.microsoft.com/windows-hardware/drivers/network/creating-a-nic-switch).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

### Interfacing to a Virtual Bus Driver

If an independent hardware vendor (IHV) provides a virtual bus driver (VBD) as part of its SR-IOV [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall), its miniport driver must not call **NdisMEnableVirtualization**. Instead, the driver must interface with the VBD through a private communication channel, and request that the VBD call [EnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-enable_virtualization). This function is provided by the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface that is supported by the underlying PCI bus driver.

The VBD that runs in the Hyper-V parent partition's management operating system can query the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface by issuing an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request to its physical device object (PDO) on the PCI bus. This request must be made from IRQL = PASSIVE_LEVEL. In this request, the driver must set the *InterfaceType* parameter to GUID_PCI_VIRTUALIZATION_INTERFACE.

## See also

[EnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-enable_virtualization)

[GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85))

[OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch)

[OID_NIC_SWITCH_DELETE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-delete-switch)