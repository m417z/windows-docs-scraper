typedef struct _DS_REPL_CURSORS_3W {
  DWORD             cNumCursors;
  DWORD             dwEnumerationContext;
#if ...
  DS_REPL_CURSOR_3W rgCursor[];
#else
  DS_REPL_CURSOR_3W rgCursor[1];
#endif
} DS_REPL_CURSORS_3W;