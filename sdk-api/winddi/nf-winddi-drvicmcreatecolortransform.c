HANDLE DrvIcmCreateColorTransform(
  [in]           DHPDEV           dhpdev,
  [in]           LPLOGCOLORSPACEW pLogColorSpace,
  [in, optional] PVOID            pvSourceProfile,
  [in]           ULONG            cjSourceProfile,
  [in]           PVOID            pvDestProfile,
  [in]           ULONG            cjDestProfile,
  [in, optional] PVOID            pvTargetProfile,
  [in]           ULONG            cjTargetProfile,
  [in]           DWORD            dwReserved
);