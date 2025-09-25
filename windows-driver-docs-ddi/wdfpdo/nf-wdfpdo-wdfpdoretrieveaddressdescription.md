# WdfPdoRetrieveAddressDescription function

## Description

[Applies to KMDF only]

The **WdfPdoRetrieveAddressDescription** method retrieves the [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) that is associated with a specified framework device object.

## Parameters

### `Device` [in]

A handle to a framework device object that represents the device's physical device object (PDO).

### `AddressDescription` [in, out]

A pointer to a caller-allocated buffer that will receive the address description. The address description must contain a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *Device* handle does not represent a PDO. |
| **STATUS_INVALID_DEVICE_REQUEST** | The *Device* handle does not represent a device that was [dynamically enumerated](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration). |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## See also

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_address_description_header_init)

[WdfChildListRetrieveAddressDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrieveaddressdescription)

[WdfPdoRetrieveIdentificationDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoretrieveidentificationdescription)