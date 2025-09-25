# WdfChildListRequestChildEject function

## Description

[Applies to KMDF only]

The **WdfChildListRequestChildEject** method informs the framework that a specified device is about to be ejected from its docking station.

## Parameters

### `ChildList` [in]

A handle to a child list object.

### `IdentificationDescription` [in]

A pointer to a caller-allocated [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure.

## Return value

**WdfChildListRequestChildEject** returns **TRUE** if the operation succeeds. If an input parameter is invalid, or if the framework cannot find the device in the child list, the method returns **FALSE**.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

A bus driver can call **WdfChildListRequestChildEject** or [WdfPdoRequestEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdorequesteject) to report that the driver has detected an attempt to eject one of its enumerated child devices from the device's docking station. For example, the driver might detect that a user has pushed an eject button.

If the driver is using dynamic bus enumeration and if the device's identification description is available, the driver can call **WdfChildListRequestChildEject**. If the framework device object for the device's PDO is available, the driver can call [WdfPdoRequestEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdorequesteject).

The **WdfChildListRequestChildEject** method's *IdentificationDescription* parameter identifies the device that is being ejected. The device must be a member of the child list that the *ChildList* parameter represents.

The framework uses the identification description to locate the device in the child list.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

For more information about ejectable devices, see [Supporting Ejectable Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-ejectable-devices).

#### Examples

For a code example that uses **WdfChildListRequestChildEject**, see [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice).

## See also

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WdfPdoRequestEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdorequesteject)