HRESULT WindowsInspectString2(
  UINT64                     targetHString,
  USHORT                     machine,
  PINSPECT_HSTRING_CALLBACK2 callback,
  void                       *context,
  UINT32                     *length,
  UINT64                     *targetStringAddress
);