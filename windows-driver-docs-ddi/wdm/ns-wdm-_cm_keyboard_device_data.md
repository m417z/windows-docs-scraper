# _CM_KEYBOARD_DEVICE_DATA structure

## Description

The **CM_KEYBOARD_DEVICE_DATA** structure defines a device-type-specific data record that is stored in the \\Registry\Machine\Hardware\Description tree for a keyboard peripheral if the system can collect this information during the boot process.

## Members

### `Version`

The version number of this structure.

### `Revision`

The revision of this structure.

### `Type`

The type of the keyboard.

### `Subtype`

The subtype of the keyboard.

### `KeyboardFlags`

Defined by x86 BIOS INT 16h, function 02 as:

| Bit | Defined As |
| --- | --- |
| 7 | Insert on. |
| 6 | Caps Lock on. |
| 5 | Num Lock on. |
| 4 | Scroll Lock on. |
| 3 | Alt Key is down. |
| 2 | Ctrl Key is down. |
| 1 | Left shift key is down. |
| 0 | Right shift key is down. |

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IoQueryDeviceDescription](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoReportResourceUsage](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)