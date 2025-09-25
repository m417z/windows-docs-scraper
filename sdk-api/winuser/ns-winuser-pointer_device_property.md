# POINTER_DEVICE_PROPERTY structure

## Description

Contains pointer-based device properties (Human Interface Device (HID) global items that correspond to HID usages).

## Members

### `logicalMin`

The minimum value that the device can report for this property.

### `logicalMax`

The maximum value that the device can report for this property.

### `physicalMin`

The physical minimum in Himetric.

### `physicalMax`

The physical maximum in Himetric.

### `unit`

The unit.

### `unitExponent`

The exponent.

### `usagePageId`

The usage page for the property, as documented in the HID specification.

### `usageId`

The usage of the property, as documented in the HID specification.

## Remarks

Developers can use this function to determine the properties that a device supports beyond the standard ones that are delivered through [Pointer Input Messages and Notifications](https://learn.microsoft.com/windows/win32/inputmsg/messages-and-notifications-portal). The properties map directly to HID usages.

## See also

[Structures](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/structures)