# _USAGE_AND_PAGE structure

## Description

The USAGE_AND_PAGE structure specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) and [usage ID](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of a HID control.

## Members

### `UsagePage`

Specifies a usage page.

### `Usage`

Specifies a usage ID within the usage page specified by **UsagePage**.

## Remarks

The **HidP_IsSameUsageAndPage** macro determines if two [extended usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages), represented by **USAGE_AND_PAGE** structures, are equal.

```
BOOLEAN HidP_IsSameUsageAndPage(
   USAGE_AND_PAGE u1,
   USAGE_AND_PAGE u2
);
```

*u1*

**USAGE_AND_PAGE**

Specifies an extended usage

*u2*

**USAGE_AND_PAGE**

Specifies an extended usage

**Return Value**

**BOOLEAN**

**HidP_IsSameUsageAndPage** returns one of the following status values:

**TRUE**

Usage *u1* is the same as usage *u2*.

**FALSE**

Usage *u1* is different than usage *u2*.

As defined by the USB HID standard, an extended usage is a 32-bit unsigned value. The high-order 16 bits specify the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages), and lower-order 16 bits specify the [usage ID](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidP_GetButtonsEx](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)