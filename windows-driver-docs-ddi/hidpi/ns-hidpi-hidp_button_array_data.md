## Description

The **HIDP_BUTTON_ARRAY_DATA** structure is used to get or set data for single button in a button array.

## Members

### `ArrayIndex`

The position of the button within the zero-based button array. The value will always be less than [HIDP_BUTTON_CAPS.ReportCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps). This is not an index of a button array within the parsed data.

### `On`

**TRUE** when the button at the *ArrayIndex* within the button array is on. **FALSE** when the button is off.

## Remarks

## See also

- [HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps)