typedef struct _SURFACEALIGNMENT {
  union {
    struct {
      DWORD dwStartAlignment;
      DWORD dwPitchAlignment;
      DWORD dwFlags;
      DWORD dwReserved2;
    } Linear;
    struct {
      DWORD dwXAlignment;
      DWORD dwYAlignment;
      DWORD dwFlags;
      DWORD dwReserved2;
    } Rectangular;
  };
} SURFACEALIGNMENT, *LPSURFACEALIGNMENT;