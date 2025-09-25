typedef struct {
  ULONG  ulReserved;
  ULONG  cbTag;
  LPBYTE lpTag;
  ULONG  cbEncoding;
  LPBYTE lpEncoding;
} MapiFileTagExt, *lpMapiFileTagExt;