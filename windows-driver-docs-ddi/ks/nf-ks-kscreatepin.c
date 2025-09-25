KSDDKAPI NTSTATUS KsCreatePin(
  [in]  HANDLE         FilterHandle,
  [in]  PKSPIN_CONNECT Connect,
  [in]  ACCESS_MASK    DesiredAccess,
  [out] PHANDLE        ConnectionHandle
);