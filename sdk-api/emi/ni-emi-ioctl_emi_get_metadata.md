# IOCTL_EMI_GET_METADATA IOCTL

## Description

The **IOCTL_EMI_GET_METADATA**
control code retrieves EMI metadata from a device. The metadata describe how EMI channels of the requesting device should be interpreted, and other related information.

## Parameters

### Input buffer

\<text> None. \</text>

### Input buffer length

\<text> None. \</text>

### Output buffer

\<text> The  **AssociatedIrp.SystemBuffer**
member specifies the address of a caller-allocated buffer that is used to retrieve the device-specific metadata that extended by [EMI_METADATA_V1](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v1) or [EMI_METADATA_V2](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v2) based on the interface version. On output, this structure holds the metadata of the channels of the requesting device. \</text>

### Output buffer length

\<text> The length of buffer should be either equal or greater than the value retrieved from [IOCTL_EMI_GET_METADATA_SIZE](https://learn.microsoft.com/windows/win32/api/emi/ni-emi-ioctl_emi_get_metadata_size) and it is specified in the  **Parameters.DeviceIoControl.OutputBufferLength**  member. \</text>

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

### Remarks

In order to succesfully obtain the metadata, the caller should firstly obtain the version of metadata by [IOCTL_EMI_GET_VERSION](https://learn.microsoft.com/windows/win32/api/emi/ni-emi-ioctl_emi_get_version) and secondly, the size of metadata by [IOCTL_EMI_GET_METADATA_SIZE](https://learn.microsoft.com/windows/win32/api/emi/ni-emi-ioctl_emi_get_metadata_size)

One of the important information included in the metadata is the  **Channels**  , each channel represent an instance of a energy measurement counter that exposed by the device, caller should interpret the  **Channels** dynamically according to the version.

For  **EMI_VERSION_V1** , the metadata describes a single channel by [EMI_METADATA_V1](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v1) structure.

For  **EMI_VERSION_V2** , the metadata describes multiple channels by [EMI_METADATA_V2](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v2) structure, which is a device-specific structure, therefore the size vary based on the driver implemenetation, the number of channels is specificed by  **ChannelCount**  in the metadata, which should be referenced to enumerate the  **Channels**  in the metadata. Also, the caller should use  **EMI_CHANNEL_V2_NEXT_CHANNEL**  to get each channel in a loop, this is because the size of each element in the  **Channels**  are also vary based on each  **ChannelName** , for example:

```
    BOOL Status;
    EMI_METADATA_SIZE MetadataSize;
    EMI_METADATA_V2*  MetaData;

    ZeroMemory(&MetadataSize, sizeof(EMI_METADATA_SIZE));

    //
    //  Retrieve the size of metadata.
    //

    Status = DeviceIoControl(DeviceHandle,
                             IOCTL_EMI_GET_METADATA_SIZE,
                             NULL,
                             NULL,
                             &MetadataSize,
                             sizeof(EMI_METADATA_SIZE),
                             BytesReturned,
                             NULL);

    if (!Status) {
        return Status;
    }

    //
    //  Caller allocated buffer to retrieve the metadata.
    //

    MetaData = (EMI_METADATA_V2*)HeapAlloc(
                                    GetProcessHeap(),
                                    HEAP_ZERO_MEMORY,
                                    MetadataSize.MetadataSize);

    if (NULL == MetaData) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }

    //
    //  Retrieve the metadata.
    //

    Status = DeviceIoControl(DeviceHandle,
                             IOCTL_EMI_GET_METADATA,
                             NULL,
                             NULL,
                             MetaData,
                             MetadataSize.MetadataSize,
                             BytesReturned,
                             NULL);

    //
    // Enumerate channels.
    //

    EMI_CHANNEL_V2* Channel = &MetaData->Channels[0];
    for (int i = 0 ; i < MetaData->ChannelCount ; i++) {

        //
        //  Get each EMI channel.
        //

        Channel = EMI_CHANNEL_V2_NEXT_CHANNEL(Channel);
    }

```

## See also

[EMI_METADATA_V2](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v2) \
[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)