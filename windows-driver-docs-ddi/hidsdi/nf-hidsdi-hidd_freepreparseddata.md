# HidD_FreePreparsedData function

## Description

The **HidD_FreePreparsedData** routine releases the resources that the HID class driver allocated to hold a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Parameters

### `PreparsedData` [in]

Pointer to the buffer, returned by [HidD_GetPreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata), that is freed.

## Return value

**HidD_FreePreparsedData** returns **TRUE** if it succeeds. Otherwise, it returns **FALSE** if the buffer was not a preparsed data buffer. Use [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

Only user-mode applications can call **HidD_FreePreparsedData**.

To obtain a collection's preparsed data, use [HidD_GetPreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidD_GetPreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)