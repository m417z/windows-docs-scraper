typedef struct _D3DKMT_UMDFILENAMEINFO {
  [in]  KMTUMDVERSION Version;
        WCHAR         UmdFileName[MAX_PATH];
} D3DKMT_UMDFILENAMEINFO;