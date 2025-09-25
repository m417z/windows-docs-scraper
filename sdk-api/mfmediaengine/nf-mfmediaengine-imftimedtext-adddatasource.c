HRESULT AddDataSource(
  [in]           IMFByteStream            *byteStream,
  [in, optional] LPCWSTR                  label,
  [in, optional] LPCWSTR                  language,
  [in]           MF_TIMED_TEXT_TRACK_KIND kind,
  [in]           BOOL                     isDefault,
  [out]          DWORD                    *trackId
);