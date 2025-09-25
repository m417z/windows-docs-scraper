BOOL EvtGetEventInfo(
  [in]  EVT_HANDLE            Event,
  [in]  EVT_EVENT_PROPERTY_ID PropertyId,
  [in]  DWORD                 PropertyValueBufferSize,
  [in]  PEVT_VARIANT          PropertyValueBuffer,
  [out] PDWORD                PropertyValueBufferUsed
);