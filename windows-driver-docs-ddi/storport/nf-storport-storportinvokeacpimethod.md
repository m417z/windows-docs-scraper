# StorPortInvokeAcpiMethod function

## Description

The **StorPortInvokeAcpiMethod** routine executes an ACPI method for a storage device.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address` [in, optional]

The address of the target device. This parameter is optional. If *Address* is set to **NULL**, the adapter is the target.

### `MethodName` [in]

A four-byte name for the ACPI method. For example, ((ULONG) 'DDS_') would name the _SDD, or 'Set Device Data', ACPI method for an AHCI controller.

### `InputBuffer` [in, optional]

A pointer to the input data to the method.

### `InputBufferLength` [in]

The length, in bytes, of the buffer in *InputBuffer*.

### `OutputBuffer` [in, optional]

A pointer to the output data from the method.

### `OutputBufferLength` [in]

The length, in bytes, of the buffer in *OutputBuffer*.

### `BytesReturned` [out, optional]

A pointer to the length, in bytes, of the data returned in *OutputBuffer*.

## Return value

The **StorPortInvokeAcpiMethod** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_UNSUCCESSFUL** | A general error condition exists. |
| **STOR_STATUS_INVALID_PARAMETER** | *HwDeviceExtension*, *InputBuffer*, or *OutputBuffer* is NULL.<br><br>-or-<br><br>*Address* refers to a target that does not exist. |
| **STOR_STATUS_NOT_IMPLEMENTED** | The ACPI method is not implemented. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to execute the method, or *OutputBufferLength* is not large enough for the returned data. |
| **STOR_STATUS_INVALID_IRQL** | Current IRQL > PASSIVE_LEVEL. |
| **STOR_STATUS_SUCCESS** | The method executed successfully. |

## Remarks

The **StorPortInvokeAcpiMethod** enables a miniport driver to invoke ACPI methods defined for storage controllers and storage LUNs. The method names are four-byte character strings that occupy a **ULONG** value in *MethodName*.