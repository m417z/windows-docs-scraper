typedef struct _BLOB {
  ULONG cbSize;
#if ...
  BYTE  *pBlobData;
#else
  BYTE  *pBlobData;
#endif
} BLOB, *LPBLOB;