HANDLE OEMIcmCreateColorTransform(
                 DHPDEV           dhpdev,
                 LPLOGCOLORSPACEW pLogColorSpace,
  [in, optional] PVOID            pvSourceProfile,
                 ULONG            cjSourceProfile,
  [in]           PVOID            pvDestProfile,
                 ULONG            cjDestProfile,
  [in, optional] PVOID            pvTargetProfile,
                 ULONG            cjTargetProfile,
                 DWORD            dwReserved
);