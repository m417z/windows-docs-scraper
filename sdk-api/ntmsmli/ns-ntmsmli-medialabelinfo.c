typedef struct {
  WCHAR LabelType[NTMSMLI_MAXTYPE];
  DWORD LabelIDSize;
  BYTE  LabelID[NTMSMLI_MAXIDSIZE];
  WCHAR LabelAppDescr[NTMSMLI_MAXAPPDESCR];
} MediaLabelInfo, *pMediaLabelInfo;