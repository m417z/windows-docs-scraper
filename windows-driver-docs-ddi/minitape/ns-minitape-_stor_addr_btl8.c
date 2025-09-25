typedef struct _STOR_ADDR_BTL8 {
  USHORT Type;
  USHORT Port;
  ULONG  AddressLength;
  UCHAR  Path;
  UCHAR  Target;
  UCHAR  Lun;
  UCHAR  Reserved;
} STOR_ADDR_BTL8, *PSTOR_ADDR_BTL8;