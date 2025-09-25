HRESULT GetDiskSpaceInformation(
  [out] ULONGLONG *pcbVolumeTotal,
  [out] ULONGLONG *pcbLimit,
  [out] ULONGLONG *pcbUsed,
  [out] ULONGLONG *pcbUnpinnedLimit,
  [out] ULONGLONG *pcbUnpinnedUsed
);