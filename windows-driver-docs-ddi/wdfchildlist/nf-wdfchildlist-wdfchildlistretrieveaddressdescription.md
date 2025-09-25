# WdfChildListRetrieveAddressDescription function

## Description

[Applies to KMDF only]

The **WdfChildListRetrieveAddressDescription** method locates a child device that has a specified [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) and retrieves the device's [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

## Parameters

### `ChildList` [in]

A handle to a child list object.

### `IdentificationDescription` [in]

A pointer to a caller-allocated [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies a driver-supplied child identification description.

### `AddressDescription` [in, out]

A pointer to a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure that identifies a child address description. The framework fills in this description.

## Return value

**WdfChildListRetrieveAddressDescription** returns STATUS_SUCCESS, or another status value for which [NT_SUCCESS(status)](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) equals **TRUE**, if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter was invalid. |
| **STATUS_NO_SUCH_DEVICE** | No device matched the specified identification description. |
| **STATUS_INVALID_DEVICE_REQUEST** | The child list did not contain address descriptions, or the size of the address description that *AddressDescription* specified was incorrect. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example searches a child list for a child device whose identification description contains the value that is specified by **SomeValue**. If **WdfChildListRetrieveAddressDescription** locates the device, it retrieves the device's address description.

```cpp
MY_IDENTIFICATION_DESCRIPTION  id;
MY_ADDRESS_DESCRIPTION  addrDescrip;

WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT(
                                                 &id.Header,
                                                 sizeof(id)
                                                 );
WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT(
                                          &addrDescrip.Header,
                                          sizeof(addrDescrip)
                                          );

id.DeviceIdentifier = SomeValue;
status = WdfChildListRetrieveAddressDescription(
                                                list,
                                                &idDescrip.Header,
                                                &addrDescrip.Header
                                                );
if (!NT_SUCCESS(status) {
    return status;
}
```

## See also

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_address_description_header_init)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init)