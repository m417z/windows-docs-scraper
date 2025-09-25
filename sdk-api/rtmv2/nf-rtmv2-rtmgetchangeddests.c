DWORD RtmGetChangedDests(
  [in]      RTM_ENTITY_HANDLE RtmRegHandle,
  [in]      RTM_NOTIFY_HANDLE NotifyHandle,
  [in, out] PUINT             NumDests,
  [out]     PRTM_DEST_INFO    ChangedDests
);