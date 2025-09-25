# _PosStatisticsHeader structure

## Description

This structure defines Unified Point of Service (UPOS) standard information about a device. This structure is the header for an incoming statistic.

## Members

### `EntryCount`

Indicates the number of statistics that follow this header.

### `DeviceInformation`

A [PosDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ns-pointofservicecommontypes-_posdeviceinformation) structure that contains UPOS standard information about the device, such as its category, manufacturer, and firmware revision.

### `DataLength`

Indicates the length, in bytes, of the **PosStatisticsHeader** and the buffer of [PosValueStatisticsEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posvaluestatisticsentry) that follow this structure in memory.