# HidD_GetAttributes function

## Description

The **HidD_GetAttributes** routine returns the attributes of a specified [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### `HidDeviceObject` [in]

Specifies an open handle to a top-level collection.

### `Attributes` [out]

Pointer to a caller-allocated [HIDD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/ns-hidsdi-_hidd_attributes) structure that returns the attributes of the collection specified by *HidDeviceObject*.

## Return value

**HidD_GetAttributes** returns **TRUE** if succeeds; otherwise, it returns **FALSE**.

## Remarks

Only user-mode applications can call **HidD_GetAttributes**. Kernel-mode drivers can use [IOCTL_HID_GET_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_information).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/ns-hidsdi-_hidd_attributes)

[IOCTL_HID_GET_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_information)