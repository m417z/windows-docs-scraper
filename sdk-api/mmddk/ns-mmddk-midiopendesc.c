typedef struct midiopendesc_tag {
  HMIDI          hMidi;
  DWORD_PTR      dwCallback;
  DWORD_PTR      dwInstance;
  DWORD_PTR      dnDevNode;
  DWORD          cIds;
  MIDIOPENSTRMID rgIds[1];
} MIDIOPENDESC;