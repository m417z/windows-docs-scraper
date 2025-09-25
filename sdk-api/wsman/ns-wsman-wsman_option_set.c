typedef struct _WSMAN_OPTION_SET {
  DWORD        optionsCount;
  WSMAN_OPTION *options;
  BOOL         optionsMustUnderstand;
} WSMAN_OPTION_SET;