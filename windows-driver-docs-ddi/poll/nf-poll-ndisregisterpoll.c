NDIS_EXPORTED_ROUTINE NDIS_STATUS NdisRegisterPoll(
  [_In_]     NDIS_HANDLE                     NdisHandle,
  [_In_opt_] void                            *Context,
  [_In_]     NDIS_POLL_CHARACTERISTICS const *Characteristics,
  [_Out_]    NDIS_POLL_HANDLE                *PollHandle
);