HRESULT MFGetMFTMerit(
  [in, out] IUnknown   *pMFT,
  [in]      UINT32     cbVerifier,
  [in]      const BYTE *verifier,
  [out]     DWORD      *merit
);