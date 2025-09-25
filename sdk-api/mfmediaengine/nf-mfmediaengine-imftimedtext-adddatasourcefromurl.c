HRESULT AddDataSourceFromUrl(
  [in]           LPCWSTR                  url,
  [in, optional] LPCWSTR                  label,
  [in, optional] LPCWSTR                  language,
  [in]           MF_TIMED_TEXT_TRACK_KIND kind,
  [in]           BOOL                     isDefault,
  [out]          DWORD                    *trackId
);