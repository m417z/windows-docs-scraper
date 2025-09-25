typedef struct _D3DKMT_OPENGLINFO {
        WCHAR UmdOpenGlIcdFileName[MAX_PATH];
  [out] ULONG Version;
  [in]  ULONG Flags;
} D3DKMT_OPENGLINFO;