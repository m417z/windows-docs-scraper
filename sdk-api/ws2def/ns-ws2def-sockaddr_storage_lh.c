typedef struct sockaddr_storage {
  ADDRESS_FAMILY ss_family;
  CHAR           __ss_pad1[_SS_PAD1SIZE];
  __int64        __ss_align;
  CHAR           __ss_pad2[_SS_PAD2SIZE];
} SOCKADDR_STORAGE_LH, *PSOCKADDR_STORAGE_LH, *LPSOCKADDR_STORAGE_LH;