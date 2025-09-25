# _URS_HARDWARE_EVENT enumeration

## Description

Defines values for the hardware events that a client driver for a USB dual-role controller can report.

## Constants

### `UrsHardwareEventNone`

Internal use only.

### `UrsHardwareEventDetach`

A detach event occurred on a port of a USB Type-C system.

### `UrsHardwareEventIdGround`

This event indicates that the ID pin is grounded.

### `UrsHardwareEventIdFloat`

This event indicates that the ID pin is floating.

### `UrsHardwareEventPortTypeDfp`

The Type-C connector has resolved to DFP. Not to be used directly by the URS client driver.

### `UrsHardwareEventPortTypeUfp`

The Type-C connector has resolved to UFP. Not to be used directly by the URS client driver.

## Remarks

Values defined for USB Type-C systems should not be directly used by the client driver. Instead the driver should report that it does not support hardware event reporting by calling [UrsSetHardwareEventSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-urssethardwareeventsupport). These hardware events are detected by a USB Type-C connector driver, see [USB Type-C connector driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/).