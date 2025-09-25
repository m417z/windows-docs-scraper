# WdfChildListUpdateChildDescriptionAsMissing function

## Description

[Applies to KMDF only]

The **WdfChildListUpdateChildDescriptionAsMissing** method informs the framework that a specified child device is currently unplugged or otherwise unavailable.

## Parameters

### `ChildList` [in]

A handle to a child list object.

### `IdentificationDescription` [in]

A pointer to a caller-allocated [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies a driver-supplied child [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

## Return value

**WdfChildListUpdateChildDescriptionAsMissing** returns STATUS_SUCCESS, or another status value for which [NT_SUCCESS(status)](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) equals **TRUE**, if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter was invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The size of the structure that *IdentificationDescription* points to was incorrect. |
| **STATUS_NO_SUCH_DEVICE** | The specified device was not found in the child list. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can report that a device is unavailable even if the driver never called [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent) to report that the device was present. In this case, the **WdfChildListUpdateChildDescriptionAsMissing** method just returns STATUS_NO_SUCH_DEVICE.

If you want to report that all devices in a child list are unavailable, your driver can simply call [WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan), followed immediately by [WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan), instead of calling **WdfChildListUpdateChildDescriptionAsMissing** for each device.

For more information about child devices and child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example informs the framework that a child device with a specified serial number is unavailable.

```cpp
PDO_IDENTIFICATION_DESCRIPTION  description;
NTSTATUS  status;

WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT(
                                                 &description.Header,
                                                 sizeof(description)
                                                 );

description.SerialNo = SerialNo;
status = WdfChildListUpdateChildDescriptionAsMissing(
                                                     list,
                                                     &description.Header
                                                     );
```

## See also

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init)

[WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent)