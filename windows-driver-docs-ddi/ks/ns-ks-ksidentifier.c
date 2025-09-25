typedef struct {
  union {
    struct {
      GUID  Set;
      ULONG Id;
      ULONG Flags;
    } _IDENTIFIER;
    struct {
      GUID  Set;
      ULONG Id;
      ULONG Flags;
    };
    LONGLONG Alignment;
  };
} KSIDENTIFIER, *PKSIDENTIFIER;