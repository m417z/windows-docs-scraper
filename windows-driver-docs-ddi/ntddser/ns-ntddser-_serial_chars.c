typedef struct _SERIAL_CHARS {
  UCHAR EofChar;
  UCHAR ErrorChar;
  UCHAR BreakChar;
  UCHAR EventChar;
  UCHAR XonChar;
  UCHAR XoffChar;
} SERIAL_CHARS, *PSERIAL_CHARS;