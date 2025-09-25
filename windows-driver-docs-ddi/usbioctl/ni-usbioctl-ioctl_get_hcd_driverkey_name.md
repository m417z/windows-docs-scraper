# IOCTL_GET_HCD_DRIVERKEY_NAME IOCTL

## Description

The **IOCTL_GET_HCD_DRIVERKEY_NAME** I/O control request retrieves the driver key name in the registry for a USB host controller driver.

**IOCTL_GET_HCD_DRIVERKEY_NAME** is a user-mode I/O control request. This request targets the USB host controller (GUID_DEVINTERFACE_USB_HOST_CONTROLLER).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member specifies the address of a caller-allocated buffer that contains a [USB_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hcd_driverkey_name) structure. On output, this structure holds the driver key name. For more information, see Remarks.

### Output buffer length

The size of this buffer is specified in the **Parameters.DeviceIoControl.OutputBufferLength** member.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## Remarks

To get the driver key name in the registry, you must perform the following tasks:

1. Declare a variable of the type [USB_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hcd_driverkey_name).
2. Send an **IOCTL_GET_HCD_DRIVERKEY_NAME** request by specifying the address and size of the variable in the output parameters. On return, the **ActualLength** member of [USB_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hcd_driverkey_name) contains the length required to allocate a buffer to hold a **USB_HCD_DRIVERKEY_NAME** that is populated with the driver key name.
3. Allocate memory for a buffer to hold a [USB_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hcd_driverkey_name) structure. The size of the buffer must be the received **ActualLength** value.
4. Send an **IOCTL_GET_HCD_DRIVERKEY_NAME** request by passing a pointer to the allocated buffer and its size in the output parameters. On return, the **DriverKeyName** member of [USB_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hcd_driverkey_name) is a null-terminated Unicode string that contains the name of the driver key associated with the host controller driver.

The following example code shows how to send the **IOCTL_GET_HCD_DRIVERKEY_NAME** I/O control request.

```cpp

/*++

Routine Description:

This routine prints the name of the driver key associated with
the specified host controller driver.

Arguments:

HCD - Handle for host controller driver.

Return Value: Boolean that indicates success or failure.

--*/

BOOL GetHCDDriverKeyName (HANDLE  HCD)
{
    BOOL                    success;
    ULONG                   nBytes;
    USB_HCD_DRIVERKEY_NAME  driverKeyName;
    PUSB_HCD_DRIVERKEY_NAME driverKeyNameW;

    driverKeyNameW = NULL;

    // 1. Get the length of the name of the driver key.
    success = DeviceIoControl(HCD,
        IOCTL_GET_HCD_DRIVERKEY_NAME,
        NULL,
        0,
        &driverKeyName,
        sizeof(driverKeyName),
        &nBytes,
        NULL);

    if (!success)
    {
        printf("First IOCTL_GET_HCD_DRIVERKEY_NAME request failed\n");
        goto GetHCDDriverKeyNameDone;
    }

    //2. Get the length of the driver key name.
    nBytes = driverKeyName.ActualLength;

    if (nBytes <= sizeof(driverKeyName))
    {
        printf("Incorrect length received by IOCTL_GET_HCD_DRIVERKEY_NAME.\n");
        goto GetHCDDriverKeyNameDone;
    }

    // 3. Allocate memory for a USB_HCD_DRIVERKEY_NAME
    //    to hold the driver key name.
    driverKeyNameW = (PUSB_HCD_DRIVERKEY_NAME) malloc(nBytes);

    if (driverKeyNameW == NULL)
    {
        printf("Failed to allocate memory.\n");
        goto GetHCDDriverKeyNameDone;
    }

    // Get the name of the driver key of the device attached to
    // the specified port.
    success = DeviceIoControl(HCD,
        IOCTL_GET_HCD_DRIVERKEY_NAME,
        NULL,
        0,
        driverKeyNameW,
        nBytes,
        &nBytes,
        NULL);

    if (!success)
    {
        printf("Second IOCTL_GET_HCD_DRIVERKEY_NAME request failed.\n");
        goto GetHCDDriverKeyNameDone;
    }

    // print the driver key name.
    printf("Driver Key Name: %s.\n", driverKeyNameW->DriverKeyName);

GetHCDDriverKeyNameDone:

    // Cleanup.
    // Free the allocated memory for USB_HCD_DRIVERKEY_NAME.

    if (driverKeyNameW != NULL)
    {
        free(driverKeyNameW);
        driverKeyNameW = NULL;
    }

    return success;
}

```

## See also

[USB_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hcd_driverkey_name)