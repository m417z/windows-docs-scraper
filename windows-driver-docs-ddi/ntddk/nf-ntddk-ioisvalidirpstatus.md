# IoIsValidIrpStatus function

## Description

The **IoIsValidIrpStatus** routine validates the specified NTSTATUS status code value.

## Parameters

### `Status` [in]

The status code to be validated.

## Return value

**IoIsValidIrpStatus** returns **TRUE** if the *Status* parameter is a well-formed NTSTATUS value. Otherwise, the routine returns **FALSE**.

## Remarks

Driver developers can define custom NTSTATUS values for use as status codes for [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) requests. Drivers can call **IoIsValidIrpStatus** to validate the status codes for these requests. This routine is useful for detecting an uninitialized or corrupted **Status** value in the [I/O status block](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-status-blocks) of an IRP.

**IoIsValidIrpStatus** detects invalid status codes that obviously violate the rules for defining custom NTSTATUS values, but might not detect invalid status codes that appear to follow the rules. The routine might return **TRUE** for a *Status* parameter that is not a valid NTSTATUS code value, but rarely, if ever, returns **FALSE** for a valid NTSTATUS code.

**IoIsValidIrpStatus** examines the **Sev**, **Facility**, and **Code** fields in the *Status* parameter value to determine whether the combination of values in these fields conforms to the published guidelines. If the **C** bit of the *Status* parameter is set, **IoIsValidIrpStatus** returns **TRUE** regardless of the other field values in *Status*.

For more information about these fields, see [Defining New NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-new-ntstatus-values).

## See also

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)