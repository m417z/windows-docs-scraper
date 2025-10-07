typedef struct tagSYSTEM_EVENT_DATA {
  BYTE  bModifier;
  WCHAR wKey;
  LONG  xPos;
  LONG  yPos;
  BYTE  bCursorMode;
  DWORD dwButtonState;
} SYSTEM_EVENT_DATA;