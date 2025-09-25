# DXGKDDI_WRITEVIRTUALFUNCTIONCONFIG callback function

## Description

This callback function allows the non-privileged virtual machine to set the contents of a PCI Express SR-IOV Virtual Function’s configuration space values.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in, out]

A pointer to a DXGKARG_WRITEVIRTUALFUNCTIONCONFIG structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_WRITEVIRTUALFUNCTIONCONFIG DxgkddiWritevirtualfunctionconfig;

// Definition

NTSTATUS DxgkddiWritevirtualfunctionconfig
(
	HANDLE Context
	DXGKARG_WRITEVIRTUALFUNCTIONCONFIG * pArgs
)
{...}

```

## Remarks

Granting the guest partition direct access to the config space can be problematic, so this function provides a method of safely accessing the virtual functions config block.

Note that this should return values and side effects as if written to the virtual device’s config block. Use of this interface may accomplish the write by handling it internally inside the driver supplying the interface or by calling [SetVirtualFunctionData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_virtual_device_data) (from the PCI_VIRTUALIZATION_INTERFACE of the lower level PDO) or some combination of the two.

## See also