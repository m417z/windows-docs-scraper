typedef struct _D3DKMT_SEGMENTSIZEINFO {
  [out] D3DKMT_ALIGN64 ULONGLONG DedicatedVideoMemorySize;
  [out] D3DKMT_ALIGN64 ULONGLONG DedicatedSystemMemorySize;
  [out] D3DKMT_ALIGN64 ULONGLONG SharedSystemMemorySize;
} D3DKMT_SEGMENTSIZEINFO;