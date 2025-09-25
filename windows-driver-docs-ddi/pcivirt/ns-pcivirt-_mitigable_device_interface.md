# _MITIGABLE_DEVICE_INTERFACE structure

## Description

Stores function pointers to callback functions implemented by the physical function (PF) driver for the mitigable device interface.

## Members

### `Size`

Size of this structure.

### `Version`

Version of this structure

### `Context`

Driver-defined context passed by the driver.

### `InterfaceReference`

Pointer to a routine that increments the number of references to this interface. For more information about this routine, see [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference).

### `InterfaceDereference`

Pointer to a routine that decrements the number of references to this interface. For more information about this routine, see [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference).

### `ReadWriteMitigatedRegister`

Pointer to the driver's implementation of the [READ_WRITE_MITIGATED_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-read_write_mitigated_register) callback function.

## Syntax

```cpp
typedef struct _MITIGABLE_DEVICE_INTERFACE {
  USHORT                         Size;
  USHORT                         Version;
  PVOID                          Context;
  PINTERFACE_REFERENCE           InterfaceReference;
  PINTERFACE_REFERENCE           InterfaceDereference;
  PREAD_WRITE_MITIGATED_REGISTER ReadWriteMitigatedRegister;
} MITIGABLE_DEVICE_INTERFACE, MITIGABLE_DEVICE_INTERFACE;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. This function reads and writes mitigated address spaces, in the form required by GUID_MITIGABLE_DEVICE_INTERFACE.

The PF driver registers its implementation by setting the **ReadVfConfig** member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).