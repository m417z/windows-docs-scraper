# PROCESS_TELEMETRY_ID_INFORMATION_TYPE structure

Specifies metadata about the process.

## Members

**HeaderSize**

The size, in bytes, of the resource header data that follows.

**ProcessId**

The ID of the process.

**ProcessStartKey**

The time the process was created.

**CreateInterruptTime**

Current interrupt-time count.

Interrupt-time count is not subject to adjustments by users or the Windows time service (see [Interrupt Time](https://learn.microsoft.com/windows/win32/SysInfo/interrupt-time)).

**CreateUnbiasedInterruptTime**

Current unbiased interrupt-time count.

Unbiased interrupt-time means that only time that the system is in the working state is counted—therefore, the interrupt-time count is not "biased" by time the system spends in sleep or hibernation (see [Interrupt Time](https://learn.microsoft.com/windows/win32/SysInfo/interrupt-time)).

**ProcessSequenceNumber**

The process sequence number.

**SessionCreateTime**

Date and time the session was created.

**SessionId**

The unique session associated with client connection.

**BootId**

The boot ID.

**ImageChecksum**

The image file checksum.

**ImageTimeDateStamp**

The image file time stamp.

**UserSidOffset**

The User Sid offset.

**ImagePathOffset**

The name and path of the image offset.

**PackageNameOffset**

The package name offset.

**RelativeAppNameOffset**

The relative app name offset.

**CommandLineOffset**

The process command line offset.

## Remarks

This struct has no associated import library or header file.

## Requirements

| Requirement | Value |
|-----------------------------------|---------------------------------|
| Minimum supported client | Windows 10 |
| DLL | N/A |