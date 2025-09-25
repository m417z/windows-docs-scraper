HRESULT LockRect(
  [in]  D3DCUBEMAP_FACES FaceType,
  [in]  UINT             Level,
  [out] D3DLOCKED_RECT   *pLockedRect,
  [in]  const RECT       *pRect,
  [in]  DWORD            Flags
);