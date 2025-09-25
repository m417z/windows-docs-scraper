PKSEVENT_ENTRY StreamClassGetNextEvent(
  [in, optional] PVOID             HwInstanceExtension_OR_HwDeviceExtension,
  [in, optional] PHW_STREAM_OBJECT HwStreamObject,
  [in, optional] GUID              *EventGuid,
  [in]           ULONG             EventItem,
  [in, optional] PKSEVENT_ENTRY    CurrentEvent
);