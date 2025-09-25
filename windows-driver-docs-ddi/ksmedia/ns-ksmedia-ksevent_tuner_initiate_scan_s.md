# KSEVENT_TUNER_INITIATE_SCAN_S structure

## Description

The KSEVENT_TUNER_INITIATE_SCAN_S structure is used in the [KSEVENT_TUNER_INITIATE_SCAN](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-tuner-initiate-scan) event within the [EVENTSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/eventsetid-tuner) event set.

## Members

### `EventData`

A structure of type [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) that specifies the standard event structure, which contains the event handle that the driver notifies about the scan operation.

### `StartFrequency`

The initial frequency, in Hz, for a scan operation.

### `EndFrequency`

The final frequency, in Hz, for a scan operation.

## See also

[EVENTSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/eventsetid-tuner)

[KSEVENT_TUNER_INITIATE_SCAN](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-tuner-initiate-scan)