TDHSTATUS TdhGetEventMapInformation(
  [in]      PEVENT_RECORD   pEvent,
  [in]      PWSTR           pMapName,
  [out]     PEVENT_MAP_INFO pBuffer,
  [in, out] ULONG           *pBufferSize
);