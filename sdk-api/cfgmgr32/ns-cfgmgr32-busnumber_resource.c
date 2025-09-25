typedef struct BusNumber_Resource_s {
  BUSNUMBER_DES   BusNumber_Header;
  BUSNUMBER_RANGE BusNumber_Data[ANYSIZE_ARRAY];
} BUSNUMBER_RESOURCE, *PBUSNUMBER_RESOURCE;