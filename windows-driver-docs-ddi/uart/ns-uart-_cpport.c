typedef struct _CPPORT {
  PUCHAR                            Address;
  ULONG                             BaudRate;
  USHORT                            Flags;
  UCHAR                             ByteWidth;
  UART_HARDWARE_READ_INDEXED_UCHAR  Read;
  UART_HARDWARE_WRITE_INDEXED_UCHAR Write;
} CPPORT, *PCPPORT;