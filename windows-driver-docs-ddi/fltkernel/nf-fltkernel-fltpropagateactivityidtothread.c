NTSTATUS FLTAPI FltPropagateActivityIdToThread(
  [in]     PFLT_CALLBACK_DATA CallbackData,
  [in/out] LPGUID             PropagateId,
  [out]    LPCGUID            *OriginalId
);