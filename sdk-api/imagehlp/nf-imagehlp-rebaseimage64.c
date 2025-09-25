BOOL IMAGEAPI ReBaseImage64(
  [in]      PCSTR   CurrentImageName,
  [in]      PCSTR   SymbolPath,
  [in]      BOOL    fReBase,
  [in]      BOOL    fRebaseSysfileOk,
  [in]      BOOL    fGoingDown,
  [in]      ULONG   CheckImageSize,
  [out]     ULONG   *OldImageSize,
  [out]     ULONG64 *OldImageBase,
  [out]     ULONG   *NewImageSize,
  [in, out] ULONG64 *NewImageBase,
  [in]      ULONG   TimeStamp
);