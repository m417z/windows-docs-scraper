WINSETUPAPI BOOL SetupDiLoadClassIcon(
  [in]            const GUID *ClassGuid,
  [out, optional] HICON      *LargeIcon,
  [out, optional] PINT       MiniIconIndex
);