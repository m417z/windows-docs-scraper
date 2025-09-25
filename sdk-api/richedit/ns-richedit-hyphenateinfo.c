typedef struct tagHyphenateInfo {
  SHORT cbSize;
  SHORT dxHyphenateZone;
  void((WCHAR *,LANGID, long,HYPHRESULT *) * )pfnHyphenate;
} HYPHENATEINFO;