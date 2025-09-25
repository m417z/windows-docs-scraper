WINSETUPAPI BOOL SetupEnumInfSectionsW(
  [in]            HINF  InfHandle,
  [in]            UINT  Index,
  [out, optional] PWSTR Buffer,
  [in]            UINT  Size,
  [out, optional] UINT  *SizeNeeded
);