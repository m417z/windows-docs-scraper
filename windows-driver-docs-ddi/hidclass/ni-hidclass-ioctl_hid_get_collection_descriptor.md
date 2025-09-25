# IOCTL_HID_GET_COLLECTION_DESCRIPTOR IOCTL

## Description

The IOCTL_HID_GET_COLLECTION_DESCRIPTOR request obtains a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data), which the HID class driver extracted from the physical device's report descriptor during device initialization.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer specified by **Irp->UserBuffer**.

### Input buffer length

### Output buffer

**Irp->UserBuffer** is a PVOID pointer to a requester-allocated buffer that the HID class driver uses to return a variable length **_HIDP_PREPARSED_DATA** structure. This buffer must be allocated from nonpaged pool.

### Output buffer length

The size, in bytes, of the preparsed data structure is obtained using [IOCTL_HID_GET_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_information).

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the following fields of **Irp->IoStatus**:

* **Information** is set to size, in bytes, of the preparsed data.
* **Status** is set to STATUS_SUCCESS if the preparsed data was retrieved without error. Otherwise, it is set to an appropriate NTSTATUS error code. If the requester-supplied output buffer is not large enough to hold the preparsed data, then status is set to STATUS_INVALID_BUFFER_SIZE.

## Remarks

The **_HIDP_PREPARSED_DATA** structure contains a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

```
typedef struct _HIDP_PREPARSED_DATA * PHIDP_PREPARSED_DATA;

```

A user-mode application calls [HidD_GetPreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata) to obtain a top-level collection's preparsed data in a variable length _HIDP_PREPARSED_DATA structure.

A kernel-mode driver uses an **IOCTL_HID_GET_COLLECTION_DESCRIPTOR** request to obtain a pointer to a top-level collection's preparsed data.

The internal structure of a _HIDP_PREPARSED_DATA structure is reserved for internal system use.

## See also

[HidD_FreePreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_freepreparseddata)

[HidD_GetPreparsedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)