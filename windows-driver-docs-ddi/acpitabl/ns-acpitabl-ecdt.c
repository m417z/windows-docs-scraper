typedef struct {
  DESCRIPTION_HEADER Header;
  GEN_ADDR           Control;
  GEN_ADDR           Data;
  ULONG              Uid;
  UCHAR              GpeBit;
  CHAR               Id[ANYSIZE_ARRAY];
} ECDT, *PECDT;