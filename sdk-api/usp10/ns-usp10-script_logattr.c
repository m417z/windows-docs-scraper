typedef struct tag_SCRIPT_LOGATTR {
  BYTE fSoftBreak : 1;
  BYTE fWhiteSpace : 1;
  BYTE fCharStop : 1;
  BYTE fWordStop : 1;
  BYTE fInvalid : 1;
  BYTE fReserved : 3;
} SCRIPT_LOGATTR;