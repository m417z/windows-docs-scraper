DWORD GetClusterNotifyV2(
  [in]                HCHANGE                 hChange,
  [out]               DWORD_PTR               *lpdwNotifyKey,
  [in, out, optional] PNOTIFY_FILTER_AND_TYPE pFilterAndType,
  [in, out, optional] BYTE                    *buffer,
  [in, out, optional] LPDWORD                 lpbBufferSize,
  [in, out, optional] LPWSTR                  lpszObjectId,
  [in, out, optional] LPDWORD                 lpcchObjectId,
  [in, out, optional] LPWSTR                  lpszParentId,
  [in, out, optional] LPDWORD                 lpcchParentId,
  [in, out, optional] LPWSTR                  lpszName,
  [in, out, optional] LPDWORD                 lpcchName,
  [in, out, optional] LPWSTR                  lpszType,
  [in, out, optional] LPDWORD                 lpcchType,
  [in, optional]      DWORD                   dwMilliseconds
);