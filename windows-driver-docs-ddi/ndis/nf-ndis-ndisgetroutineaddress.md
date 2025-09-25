# NdisGetRoutineAddress function

## Description

The
**NdisGetRoutineAddress** function returns the address of a routine given the routine's name.

## Parameters

### `NdisRoutineName` [in]

A pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that specifies the
string that contains the name of a routine.

## Return value

Returns the address of the routine whose name is specified at
*NdisRoutineName* if the routine is available; otherwise, **NULL**.

## Remarks

An NDIS driver can use
**NdisGetRoutineAddress** to obtain the address of an exported NDIS routine. The driver can then use
this address to call the NDIS routine.

An NDIS driver can use
**NdisGetRoutineAddress** if the driver must remain backward compatible. For example, if such a driver
imports an NDIS routine that is not exported by the version of NDIS that is currently running, the I/O
manager will not load the driver on the operating system. However, the driver can first use
**NdisGetRoutineAddress** to determine whether the routine is available in the version of NDIS that is
currently running. If available, the address of the routine is returned. The driver can then use the
address to call the routine. If not available, **NULL** is returned. The driver cannot call the routine, but
the driver still loads on the operating system.

No performance improvement is gained by using the address that is returned by
**NdisGetRoutineAddress** instead of calling the specified routine by name. Therefore, do not write an
NDIS driver to use
**NdisGetRoutineAddress** if you know that the NDIS version with which the driver will run exports the
specified routine.

Typically, an NDIS driver calls
**NdisGetRoutineAddress** in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)