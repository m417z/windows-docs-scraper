# HidD_GetPreparsedData function

## Description

The **HidD_GetPreparsedData** routine returns a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Parameters

### `HidDeviceObject` [in]

Specifies an open handle to a top-level collection.

### `PreparsedData` [out]

Pointer to the address of a routine-allocated buffer that contains a collection's preparsed data in a [_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata) structure.

## Return value

**HidD_GetPreparsedData** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**. Use [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

Only user-mode applications can call **HidD_GetPreparsedData**. Kernel-mode drivers can use an [IOCTL_HID_GET_COLLECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_descriptor) request.

When an application no longer requires the preparsed data, it should call [HidD_FreePreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_freepreparseddata) to free the preparsed data buffer.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidD_FreePreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_freepreparseddata)

[IOCTL_HID_GET_COLLECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_descriptor)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)