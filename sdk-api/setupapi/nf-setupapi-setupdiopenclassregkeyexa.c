WINSETUPAPI HKEY SetupDiOpenClassRegKeyExA(
  [in, optional] const GUID *ClassGuid,
  [in]           REGSAM     samDesired,
  [in]           DWORD      Flags,
  [in, optional] PCSTR      MachineName,
                 PVOID      Reserved
);