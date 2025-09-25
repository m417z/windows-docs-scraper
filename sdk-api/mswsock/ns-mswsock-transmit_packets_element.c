typedef struct _TRANSMIT_PACKETS_ELEMENT {
  ULONG dwElFlags;
  ULONG cLength;
  union {
    struct {
      LARGE_INTEGER nFileOffset;
      HANDLE        hFile;
    };
    PVOID pBuffer;
  };
} TRANSMIT_PACKETS_ELEMENT, *PTRANSMIT_PACKETS_ELEMENT, *LPTRANSMIT_PACKETS_ELEMENT;