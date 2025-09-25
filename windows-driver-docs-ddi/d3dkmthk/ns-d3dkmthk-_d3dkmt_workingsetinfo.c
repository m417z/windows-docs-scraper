typedef struct _D3DKMT_WORKINGSETINFO {
  [out] D3DKMT_WORKINGSETFLAGS Flags;
  [out] ULONG                  MinimumWorkingSetPercentile;
  [out] ULONG                  MaximumWorkingSetPercentile;
} D3DKMT_WORKINGSETINFO;