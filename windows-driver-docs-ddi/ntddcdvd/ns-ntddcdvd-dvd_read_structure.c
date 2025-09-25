typedef struct DVD_READ_STRUCTURE {
  LARGE_INTEGER        BlockByteOffset;
  DVD_STRUCTURE_FORMAT Format;
  DVD_SESSION_ID       SessionId;
  UCHAR                LayerNumber;
} DVD_READ_STRUCTURE, *PDVD_READ_STRUCTURE;