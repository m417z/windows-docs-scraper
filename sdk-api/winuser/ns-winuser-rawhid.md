# RAWHID structure

## Description

Describes the format of the raw input from a Human Interface Device (HID).

## Members

### `dwSizeHid`

Type: **DWORD**

The size, in bytes, of each HID input in **bRawData**.

### `dwCount`

Type: **DWORD**

The number of HID inputs in **bRawData**.

### `bRawData`

Type: **BYTE[1]**

The raw input data, as an array of bytes.

## Remarks

Each [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input) can indicate several inputs, but all of the inputs come from the same HID. The size of the **bRawData** array is **dwSizeHid** * **dwCount**.

For more information, see [Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports).

## See also

**Conceptual**

[RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

[Introduction to Human Interface Devices (HID)](https://learn.microsoft.com/windows-hardware/drivers/hid/)

**Reference**

[WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input)

[Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports)