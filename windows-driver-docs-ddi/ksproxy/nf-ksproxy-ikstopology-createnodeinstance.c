HRESULT CreateNodeInstance(
  [in]           ULONG       NodeId,
  [in]           ULONG       Flags,
  [in]           ACCESS_MASK DesiredAccess,
  [in, optional] IUnknown    *UnkOuter,
  [in]           REFGUID     InterfaceId,
  [out]          LPVOID      *Interface
);