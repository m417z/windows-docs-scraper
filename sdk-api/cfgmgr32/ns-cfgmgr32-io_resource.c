typedef struct IO_Resource_s {
  IO_DES   IO_Header;
  IO_RANGE IO_Data[ANYSIZE_ARRAY];
} IO_RESOURCE, *PIO_RESOURCE;