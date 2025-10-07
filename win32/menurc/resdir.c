typedef struct {
  union
  {
      ICONRESDIR   Icon;
      CURSORDIR    Cursor;
  };
  WORD       Planes;
  WORD       BitCount;
  DWORD      BytesInRes;
  WORD       IconCursorId;
} RESDIR;