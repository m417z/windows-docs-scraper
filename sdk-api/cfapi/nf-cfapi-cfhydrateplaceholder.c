HRESULT CfHydratePlaceholder(
  [in]                HANDLE           FileHandle,
  [in]                LARGE_INTEGER    StartingOffset,
  [in]                LARGE_INTEGER    Length,
  [in]                CF_HYDRATE_FLAGS HydrateFlags,
  [in, out, optional] LPOVERLAPPED     Overlapped
);