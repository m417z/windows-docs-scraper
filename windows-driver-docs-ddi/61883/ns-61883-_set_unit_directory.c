typedef struct _SET_UNIT_DIRECTORY {
  IN ULONG      Flags;
  IN ULONG      UnitSpecId;
  IN ULONG      UnitSwVersion;
  IN OUT HANDLE hCromEntry;
} SET_UNIT_DIRECTORY, *PSET_UNIT_DIRECTORY;