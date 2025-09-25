NTSTATUS EtwWriteString(
  [in]           REGHANDLE RegHandle,
  [in]           UCHAR     Level,
  [in]           ULONGLONG Keyword,
  [in, optional] LPCGUID   ActivityId,
  [in]           PCWSTR    String
);