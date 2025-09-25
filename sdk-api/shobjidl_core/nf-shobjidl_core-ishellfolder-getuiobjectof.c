HRESULT GetUIObjectOf(
  [in]      HWND                  hwndOwner,
  [in]      UINT                  cidl,
  [in]      PCUITEMID_CHILD_ARRAY apidl,
  [in]      REFIID                riid,
  [in, out] UINT                  *rgfReserved,
  [out]     void                  **ppv
);