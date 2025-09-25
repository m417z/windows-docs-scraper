BOOL IMAGEAPI ReBaseImage(
  [in]      PCSTR     CurrentImageName,
  [in]      PCSTR     SymbolPath,
  [in]      BOOL      fReBase,
  [in]      BOOL      fRebaseSysfileOk,
  [in]      BOOL      fGoingDown,
  [in]      ULONG     CheckImageSize,
  [out]     ULONG     *OldImageSize,
  [out]     ULONG_PTR *OldImageBase,
  [out]     ULONG     *NewImageSize,
  [in, out] ULONG_PTR *NewImageBase,
  [in]      ULONG     TimeStamp
);