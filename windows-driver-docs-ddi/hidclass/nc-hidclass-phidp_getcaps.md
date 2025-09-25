# PHIDP_GETCAPS callback function

## Description

The **HidP_GetCaps** routine returns a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Parameters

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Capabilities` [out]

Pointer to a caller-allocated buffer that the routine uses to return a collection's HIDP_CAPS structure.

## Return value

**HidP_GetCaps** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the collection capability information. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The specified preparsed data is invalid. |

## Remarks

For more information about a collection's capability, see [Obtaining Collection Information](https://learn.microsoft.com/windows-hardware/drivers/hid/obtaining-collection-information).

See also [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)

[HidD_GetPreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)

[IOCTL_HID_GET_COLLECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_descriptor)

[IOCTL_HID_GET_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_information)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)