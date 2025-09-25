WINSETUPAPI BOOL SetupEnumInfSectionsA(
  [in]            HINF InfHandle,
  [in]            UINT Index,
  [out, optional] PSTR Buffer,
  [in]            UINT Size,
  [out, optional] UINT *SizeNeeded
);