typedef struct _POINTER_SEARCH_PHYSICAL {
  IN ULONG64   Offset;
  IN ULONG64   Length;
  IN ULONG64   PointerMin;
  IN ULONG64   PointerMax;
  IN ULONG     Flags;
  OUT PULONG64 MatchOffsets;
  IN ULONG     MatchOffsetsSize;
  OUT ULONG    MatchOffsetsCount;
} POINTER_SEARCH_PHYSICAL, *PPOINTER_SEARCH_PHYSICAL;