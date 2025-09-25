# StorPortSetUnitAttributes function

## Description

The **StorPortSetUnitAttributes** routine registers attributes of a storage unit device with the Storport driver.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address` [in]

A [**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_address) structure that holds the storage unit device address. This parameter must not be NULL.

### `Attributes` [in]

A [**STOR_UNIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_unit_attributes) structure with bits set to indicate the attributes supported for the unit device.

## Return value

**StorPortSetUnitAttributes** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The routine set the unit attributes successfully. |
| STOR_STATUS_INVALID_PARAMETER | One or more parameters are invalid. |

An invalid parameter can be any of the following:

* The **HwDeviceExtension** pointer is NULL.
* One or more reserved bits in **Attributes** are set.
* The unit address in **Address** is formatted incorrectly.
* A unit device is not found for the address given in **Address**.

## Remarks

A miniport driver calls this routine to register the unit attributes with Storport during completion of an SRB containing a SCSIOP_INQUIRY command request. The bits in **attributes** are set based on the data returned from the adapter for the inquiry command. Storport issues an inquiry for the unit at **Address** during a bus enumeration.

## See also

[**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_address)

[**STOR_UNIT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_unit_attributes)