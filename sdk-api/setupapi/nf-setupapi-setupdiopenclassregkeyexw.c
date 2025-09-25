WINSETUPAPI HKEY SetupDiOpenClassRegKeyExW(
  [in, optional] const GUID *ClassGuid,
  [in]           REGSAM     samDesired,
  [in]           DWORD      Flags,
  [in, optional] PCWSTR     MachineName,
                 PVOID      Reserved
);