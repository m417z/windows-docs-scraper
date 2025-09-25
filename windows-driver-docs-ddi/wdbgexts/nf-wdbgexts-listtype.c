ULONG ListType(
  [in] IN LPCSTR                   Type,
  [in] IN ULONG64                  Address,
  [in] IN USHORT                   ListByFieldAddress,
  [in] IN LPCSTR                   NextPointer,
  [in] IN PVOID                    Context,
  [in] IN PSYM_DUMP_FIELD_CALLBACK CallbackRoutine
);