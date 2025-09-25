BOOL MiniDumpReadDumpStream(
  [in]  PVOID               BaseOfDump,
  [in]  ULONG               StreamNumber,
  [out] PMINIDUMP_DIRECTORY *Dir,
  [out] PVOID               *StreamPointer,
  [out] ULONG               *StreamSize
);