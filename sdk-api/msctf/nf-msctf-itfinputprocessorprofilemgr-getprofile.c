HRESULT GetProfile(
  [in]  DWORD                    dwProfileType,
  [in]  LANGID                   langid,
  [in]  REFCLSID                 clsid,
  [in]  REFGUID                  guidProfile,
  [in]  HKL                      hkl,
  [out] TF_INPUTPROCESSORPROFILE *pProfile
);