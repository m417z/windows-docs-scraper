# IoIs32bitProcess function

## Description

The **IoIs32bitProcess** routine checks whether the originator of the current I/O request is a 32-bit user-mode application.

## Parameters

### `Irp` [in, optional]

Optional pointer to the IRP containing the current I/O request. Note that this must be the original IRP that was issued by the I/O manager. If the caller is a fast I/O dispatch routine (and thus there is no IRP), the caller should set this parameter to **NULL**.

## Return value

**IoIs32bitProcess** returns **TRUE** if the originator of the current I/O request is a 32-bit user-mode process. Otherwise, it returns **FALSE**.

## Remarks

Drivers call **IoIs32bitProcess** to determine whether an I/O request is likely to contain data elements that need to be converted, or "thunked," before they can be used in a 64-bit driver.

If the *Irp* parameter is **NULL**, and the caller is running in the context of a user-mode process, **IoIs32bitProcess** returns **TRUE** if this process is a 32-bit process.

If the *Irp* parameter is not **NULL**, it must point to an IRP that was issued by the I/O manager on behalf of a user-mode process. **IoIs32bitProcess** cannot be used to check driver-allocated IRPs. Driver-allocated IRPs, as well as kernel-mode drivers, are assumed to be 64-bit-ready.

For more information, see [Programming Issues for 64-Bit Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/programming-issues-for-64-bit-drivers).