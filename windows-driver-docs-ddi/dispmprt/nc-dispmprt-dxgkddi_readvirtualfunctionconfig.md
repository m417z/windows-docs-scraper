# DXGKDDI_READVIRTUALFUNCTIONCONFIG callback function

## Description

This routine supplies the non-privileged virtual machine with the contents of a PCI Express SR-IOV Virtual Function’s configuration space values.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in, out]

A pointer to the DXGKARG_READVIRTUALFUNCTIONCONFIG structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_READVIRTUALFUNCTIONCONFIG DxgkddiReadvirtualfunctionconfig;

// Definition

NTSTATUS DxgkddiReadvirtualfunctionconfig
(
	HANDLE Context
	DXGKARG_READVIRTUALFUNCTIONCONFIG * pArgs
)
{...}

```

## Remarks

Granting the guest partition direct access to the config space can be problematic, so this function provides a method of safely accessing the virtual functions config block.

Note that this should return values as if read from the virtual device’s config block. Use of this interface may accomplish the read by handling it internally inside the driver supplying the interface, or by calling [GetVirtualFunctionData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_data) (from the PCI_VIRTUALIZATION_INTERFACE of the lower level PDO) or some combination of the two.

Kernel mode drivers should filter the request against the Virtual Function parameters and fail if there is access request out of the allowed range.

## See also