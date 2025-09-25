HRESULT KsEvent(
  [in, optional] PKSEVENT Event,
  [in]           ULONG    EventLength,
  [in, out]      LPVOID   EventData,
  [in]           ULONG    DataLength,
  [in, out]      ULONG    *BytesReturned
);