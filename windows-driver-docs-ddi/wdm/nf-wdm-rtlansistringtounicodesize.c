//
//  NTSYSAPI
//  ULONG
//  NTAPI
//  RtlAnsiStringToUnicodeSize(
//      PANSI_STRING AnsiString
//      );
//

#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    RtlxAnsiStringToUnicodeSize(STRING)                      \
)