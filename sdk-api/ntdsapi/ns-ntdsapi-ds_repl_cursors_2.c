typedef struct _DS_REPL_CURSORS_2 {
  DWORD            cNumCursors;
  DWORD            dwEnumerationContext;
#if ...
  DS_REPL_CURSOR_2 rgCursor[];
#else
  DS_REPL_CURSOR_2 rgCursor[1];
#endif
} DS_REPL_CURSORS_2;