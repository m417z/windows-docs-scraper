BOOL GetPointerFramePenInfoHistory(
  [in]            UINT32           pointerId,
  [in, out]       UINT32           *entriesCount,
  [in, out]       UINT32           *pointerCount,
  [out, optional] POINTER_PEN_INFO *penInfo
);