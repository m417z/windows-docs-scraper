# USAGE_PROPERTIES structure

## Description

Contains device properties (Human Interface Device (HID) global items that correspond to HID usages) for any type of HID input device.

## Members

### `level`

A usage-specific value for a range-based linear control (knob or dial), an on/off control (toggle switch), a momentary control (mouse button), a one-shot control (button that triggers a single event), or re-trigger control (button that triggers a repeating event).

### `page`

The Usage Page ID, such as VR Controls Page (0x03) or Game Controls Page (0x05).

### `usage`

 The Usage ID associated with a Usage Page, such as Turn Right/Left (21) or Move Right/Left (24) for a Game Controls Page.

### `logicalMinimum`

The smallest value that the control can report.

### `logicalMaximum`

The largest value that the control can report.

### `unit`

The standard of measure used to describe a control's physical value (after converting the logical value using the *exponent* value). The HID specification defines codes for the basic units of length, mass, time, temperature, current, and luminous intensity.

### `exponent`

The value used to scale a logical value to a physical value.

### `count`

 The number of data
items contained in the report.

### `physicalMinimum`

The *logicalMinimum* expressed in physical units (converted by multiplying *logicalMinimum* by *exponent*).

### `physicalMaximum`

The *logicalMaximum* expressed in physical units (converted by multiplying *logicalMaximum* by *exponent*).

## Remarks

The HID working group publishes a set of documents that make up the HID Usage Tables (the dictionary that describes what HID devices are allowed to do). These HID Usage Tables contain a list with Usage descriptions. A Usage provides information to an application developer about the intended meaning and use of a particular item described in the Report Descriptor. For example, there is a Usage defined for the left button of a mouse. The Report Descriptor can define where in a report an application can find the current state of the mouse’s left button. The Usage Tables are broken up into several name spaces, called Usage Pages. Each Usage Page describes a set of related Usages to help organize the document. The combination of a Usage Page and Usage defines the Usage ID that uniquely identifies a specific Usage in the Usage Tables.

## See also

[Universal Serial Bus HID Usage Tables - USB.org](https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf)