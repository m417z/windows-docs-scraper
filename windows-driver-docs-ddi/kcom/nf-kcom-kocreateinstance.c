COMDDKAPI NTSTATUS KoCreateInstance(
  [in]           REFCLSID ClassId,
  [in, optional] IUnknown *UnkOuter,
  [in]           ULONG    ClsContext,
  [in]           REFIID   InterfaceId,
  [out]          PVOID    *Interface
);