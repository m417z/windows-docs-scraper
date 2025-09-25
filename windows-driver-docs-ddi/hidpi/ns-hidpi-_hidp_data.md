# _HIDP_DATA structure

## Description

The HIDP_DATA structure contains information about a HID control's [data index](https://learn.microsoft.com/windows-hardware/drivers/hid/data-indices) and value in a HID report.

## Members

### `DataIndex`

Specifies the data index of a control.

### `Reserved`

Reserved for internal system use only.

### `RawValue`

Contains the binary data extracted from a report if the control is a value.

### `On`

Specifies, if **TRUE** and the control is a button, that the button is set to ON (1). Otherwise, if **On** is **FALSE** and the control is a button, the button is set to OFF (zero).

## Remarks

See [Extracting and Setting Control Data by Data Indices](https://learn.microsoft.com/windows-hardware/drivers/hid/extracting-and-setting-control-data-by-data-indices).

## See also

[HidP_GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getdata)

[HidP_SetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setdata)