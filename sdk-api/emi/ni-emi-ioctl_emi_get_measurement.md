# IOCTL_EMI_GET_MEASUREMENT IOCTL

## Description

The **IOCTL_EMI_GET_MEASUREMENT**
control code retrieves the current energy measurement and the time at which the measurement was taken.

## Parameters

### Input buffer

\<text> None. \</text>

### Input buffer length

\<text> None. \</text>

### Output buffer

\<text> The **AssociatedIrp.SystemBuffer** member specifies the address of a caller-allocated buffer that contains the measurement data from provider device driver. \</text>

### Output buffer length

\<text> The length of output buffer should be the size of [EMI_MEASUREMENT_DATA_V1](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_channel_measurement_data) or [EMI_MEASUREMENT_DATA_V2](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_measurement_data_v2) multiply by number of channels, it is specified in the  **Parameters.DeviceIoControl.OutputBufferLength** member. \</text>

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

### Remarks
For EMI version 1 and 2, the EMI measurement data reported from each channel should be accumulated and translated to the unit specified by the channel on each request, as the EMI interface of any device should be shared across the system, therefore how freqeunt the counters are being sampled and accumulated depends on how often each of its consumer requests and also the driver implementation.

For the EMI version 2, Multiple channels are exposed by the same device should be sampled at once on each request, hence the caller should use the  **ChannelCount**  in the [EMI_METADATA_V2](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v2) to traverse the channels, for example:

```

  status = DeviceIoControl(DeviceHandle,
                           IOCTL_EMI_GET_MEASUREMENT,
                           NULL,
                           NULL,
                           Data,
                           ChannelDataSize,
                           BytesReturned,
                           NULL);

  EMI_CHANNEL_V2* Channel = &MetaData->Channels[0];
  for (int i = 0 ; i < MetaData->ChannelCount && status ; i++) {

      //
      // Get energy measurement for each energy counter.
      //

      AbsoluteEnergy = Measurement->ChannelData[i].AbsoluteEnergy;
      AbsoluteTime = Measurement->ChannelData[i].AbsoluteTime;
  }

```

## See also
[EMI_METADATA_V2](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v2) \
[EMI_MEASUREMENT_DATA_V2](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_measurement_data_v2) \
[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)