typedef struct _STOR_ADDRESS {
  USHORT Type;
  USHORT Port;
  ULONG  AddressLength;
  UCHAR  AddressData[ANYSIZE_ARRAY];
} STOR_ADDRESS, *PSTOR_ADDRESS;