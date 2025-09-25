struct IEC_GESTUREINFO {
  NMHDR       nmhdr;
  IInkCursor  *Cursor;
  IInkStrokes *Strokes;
  VARIANT     Gestures;
};