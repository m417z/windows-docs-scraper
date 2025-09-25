HRESULT WindowsInspectString(
  UINT_PTR                  targetHString,
  USHORT                    machine,
  PINSPECT_HSTRING_CALLBACK callback,
  void                      *context,
  UINT32                    *length,
  UINT_PTR                  *targetStringAddress
);