## Description

When the class driver calls one of the minidriver's [StrMiniEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_event_routine) routines, it passes a pointer to an **HW_EVENT_DESCRIPTOR** structure to describe the event as enabled or disabled.

## Members

### `Enable`

This is set to **TRUE** for an enabled event, and **FALSE** for a disabled event.

### `EventEntry`

Points to the [**KSEVENT_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure that describes this event.

### `EventData`

Points to the [**KSEVENTDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that describes this instance of the event.

### `StreamObject`

Points to the [**HW_STREAM_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object) for the stream that owns the event that the class driver is enabling/disabling, or **NULL** if the event belongs to the driver as a whole.

### `DeviceExtension`

Points to the minidriver's device extension.

### `EnableEventSetIndex`

For stream events, this specifies the index of the event set within the **StreamEventsArray** member of the stream's [**HW_STREAM_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information) structure.

For device events, this specifies the index of the event set within the **DeviceEventsArray** member of the minidriver's [**HW_STREAM_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header) structure.

### `HwInstanceExtension`

Pointer to the minidriver's instance extension. The minidriver may use this buffer to record private information global to this instance of the minidriver. The minidriver sets the size of this buffer in the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter).

### `Reserved`

Reserved for system use. Do not use.

### `Reserved[2]`

Reserved for system use. Do not use.