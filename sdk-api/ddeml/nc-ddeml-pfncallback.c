PFNCALLBACK Pfncallback;

HDDEDATA Pfncallback(
  [in] UINT wType,
  [in] UINT wFmt,
  [in] HCONV hConv,
  [in] HSZ hsz1,
  [in] HSZ hsz2,
  [in] HDDEDATA hData,
  [in] ULONG_PTR dwData1,
  [in] ULONG_PTR dwData2
)
{...}