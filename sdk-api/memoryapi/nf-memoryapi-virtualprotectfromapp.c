BOOL VirtualProtectFromApp(
  [in]  PVOID  Address,
  [in]  SIZE_T Size,
  [in]  ULONG  NewProtection,
  [out] PULONG OldProtection
);