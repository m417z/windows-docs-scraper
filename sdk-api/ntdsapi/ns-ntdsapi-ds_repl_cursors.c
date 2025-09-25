typedef struct _DS_REPL_CURSORS {
  DWORD          cNumCursors;
  DWORD          dwReserved;
#if ...
  DS_REPL_CURSOR rgCursor[];
#else
  DS_REPL_CURSOR rgCursor[1];
#endif
} DS_REPL_CURSORS;