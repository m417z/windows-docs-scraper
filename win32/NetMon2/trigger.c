typedef struct _TRIGGER {
  BOOL         TriggerActive;
  BYTE         TriggerType;
  BYTE         TriggerAction;
  DWORD        TriggerFlags;
  PATTERNMATCH TriggerPatternMatch;
  DWORD        TriggerBufferSize;
  DWORD        Reserved;
} TRIGGER, *LPTRIGGER;