# WdfChildListAddOrUpdateChildDescriptionAsPresent function

## Description

[Applies to KMDF only]

The **WdfChildListAddOrUpdateChildDescriptionAsPresent** method adds a new child description to a list of children or updates an existing child description.

## Parameters

### `ChildList` [in]

A handle to a framework child list object.

### `IdentificationDescription` [in]

A pointer to a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies a child [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

### `AddressDescription` [in, optional]

A pointer to a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure that identifies a child [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration). If an address description is not needed, this parameter can be **NULL**.

## Return value

**WdfChildListAddOrUpdateChildDescriptionAsPresent** returns STATUS_SUCCESS, or another NTSTATUS-typed status value for which [NT_SUCCESS(status)](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) equals **TRUE**, if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter was invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The size of the identification description or address description was incorrect. |
| **STATUS_OBJECT_NAME_EXISTS** | A child with the supplied identification description already exists. In this case, the framework copies the supplied address description to the existing child. |
| **STATUS_INSUFFICIENT_RESOURCES** | A child description could be allocated. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfChildListAddOrUpdateChildDescriptionAsPresent** method searches the specified child list for a child that matches the supplied identification description. If a match is found, the framework updates the child's address description, if supplied, and returns STATUS_OBJECT_NAME_EXISTS. If no match is found, the framework creates a new child by using the supplied identification and address descriptions.

A driver can call **WdfChildListAddOrUpdateChildDescriptionAsPresent** to add or update a single child description. The framework immediately updates the child list and informs the Plug and Play (PnP) manager that changes have been made.

Alternatively, the driver can do the following:

1. Call [WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan) to prepare the child list for updating.
2. Call **WdfChildListAddOrUpdateChildDescriptionAsPresent** multiple times to add or update the child descriptions for all of the parent device's children.
3. Call [WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan) to process changes to the child list.

If the driver uses this alternative procedure, the framework waits until the driver calls [WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan) before updating the child list and informing the PnP manager that changes have been made. When your driver calls [WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan), the framework marks all previously reported devices as no longer being present. Therefore, the driver must call **WdfChildListAddOrUpdateChildDescriptionAsPresent** for all children, not just newly discovered children.

At some time after a driver calls **WdfChildListAddOrUpdateChildDescriptionAsPresent**, the framework calls the driver's [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) callback function so that the driver can create a device object by calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example is based on code that the [kmdf_fx2](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample contains. The example adds child descriptions to a device's default child list. It retrieves switch settings that the driver previously stored in a device object's context space and then calls **WdfChildListAddOrUpdateChildDescriptionAsPresent** for each switch that is set.

```cpp
PDEVICE_CONTEXT  pDeviceContext;
WDFCHILDLIST  list;
UCHAR  i;
NTSTATUS  status;

pDeviceContext = GetDeviceContext(Device);
list = WdfFdoGetDefaultChildList(Device);

WdfChildListBeginScan(list);

for (i = 0; i < RTL_BITS_OF(UCHAR); i++) {
    if (pDeviceContext->CurrentSwitchState & (1<<i)) {
        PDO_IDENTIFICATION_DESCRIPTION description;
        WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT(
                                                 &description.Header,
                                                 sizeof(description)
                                                 );
        description.SwitchNumber = i;

        status = WdfChildListAddOrUpdateChildDescriptionAsPresent(
                                                 list,
                                                 &description.Header,
                                                 NULL
                                                 );
        if (!NT_SUCCESS(status) && (status != STATUS_OBJECT_NAME_EXISTS)) {
            break;
        }
    }
}
WdfChildListEndScan(list);
```

## See also

[EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init)

[WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan)

[WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfFdoGetDefaultChildList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdogetdefaultchildlist)