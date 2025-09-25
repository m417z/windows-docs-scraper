VIDEOPORT_DEPRECATED VIDEOPORT_API ULONG VideoPortGetBusData(
        PVOID         HwDeviceExtension,
        BUS_DATA_TYPE BusDataType,
        ULONG         SlotNumber,
  [out] PVOID         Buffer,
        ULONG         Offset,
        ULONG         Length
);