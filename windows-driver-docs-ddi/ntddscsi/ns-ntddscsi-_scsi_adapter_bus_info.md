# _SCSI_ADAPTER_BUS_INFO structure

## Description

The SCSI_ADAPTER_BUS_INFO structure is used in conjunction with the [IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data) request to retrieve the SCSI inquiry data for all devices on a given SCSI bus.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `NumberOfBuses`

Contains the number of buses on the adapter for which inquiry data is being reported.

### `BusData`

Contains a variable length array of [SCSI_BUS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_bus_data) structures that hold the inquiry data.

## Remarks

SCSI_ADAPTER_BUS_INFO is a header structure that describes the layout of the output buffer of the [IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data) request. This request returns SCSI inquiry data for all of the logical units on all of the buses associated with a particular SCSI host bus adapter (HBA). The **BusData** member of SCSI_ADAPTER_BUS_INFO contains a variable length array of [SCSI_BUS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_bus_data) structures. This array has one element for each SCSI bus on the adapter, so its size is equal to the number of buses indicated in the **NumberOfBuses** member of SCSI_ADAPTER_BUS_INFO.

In most cases, **NumberOfBuses** will have a value of 1. Early SCSI buses were limited to 36 targets (rather than the current limit of 128), so some vendors manufactured HBAs with several buses, in order to increase the maximum number of targets. To support these older HBAs, Windows provides a mechanism for retrieving inquiry data from HBAs with multiple buses. For adapters with a single bus, **NumberOfBuses** will be one, and the **BusData** member of SCSI_ADAPTER_BUS_INFO will have only one element, but HBAs with multiple buses will generate data for multiple SCSI_BUS_DATA structures, and **NumberOfBuses** will be greater than 1.

Immediately following the array in **BusData** is the inquiry data for all of the devices on all the buses that belong to the HBA. The **InquiryDataOffset** member of each SCSI_BUS_DATA structure provides an offset to the inquiry data for the corresponding SCSI bus.

The inquiry data for each SCSI bus includes information about all of the logical units on that bus. Each logical unit's inquiry data is formatted in a structure of type [SCSI_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_inquiry_data), and all of the SCSI_INQUIRY_DATA structures for a particular bus are linked together by the **NextInquiryDataOffset** member. There will be a separate list for each SCSI bus, and the **NextInquiryDataOffset** member of the last structure in each list contains a value of zero.

The following pseudocode example illustrates how to step through the SCSI buses on an HBA, and the logical units for each bus, reading and printing the inquiry data for each logical unit:

```
VOID
PrintInquiryData(PCHAR  DataBuffer)
{
    PSCSI_ADAPTER_BUS_INFO  adapterInfo;
    PSCSI_INQUIRY_DATA inquiryData;
    ULONG i, j;

    adapterInfo = (PSCSI_ADAPTER_BUS_INFO) DataBuffer;
    for (i = 0; i < adapterInfo->NumberOfBuses; i++) {
       inquiryData = (PSCSI_INQUIRY_DATA) (DataBuffer +
          adapterInfo->BusData[i].InquiryDataOffset);
       while (adapterInfo->BusData[i].InquiryDataOffset) {
          printf(" %d   %d  %3d    %s    %.28s ",
             i,
             inquiryData->TargetId,
             inquiryData->Lun,
             (inquiryData->DeviceClaimed) ? "Y" : "N",
             &inquiryData->InquiryData[8]);
          for (j = 0; j < 8; j++) {
             printf("%02X ", inquiryData->InquiryData[j]);
          }
          printf("\n");
          if (inquiryData->NextInquiryDataOffset == 0) {
             break;
          }
          inquiryData = (PSCSI_INQUIRY_DATA) (DataBuffer +
             inquiryData->NextInquiryDataOffset);
       }
    }
    printf("\n\n");
}
```

You must use **NextInquiryDataOffset** member to locate the inquiry data for next logical unit. Do not try to do this by pointer arithmetic. The positioning of each SCSI_INQUIRY_DATA structure is potentially different for each HBA miniport driver, because it depends on data alignment requirements.

## See also

[IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data)

[SCSI_BUS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_bus_data)

[SCSI_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_inquiry_data)