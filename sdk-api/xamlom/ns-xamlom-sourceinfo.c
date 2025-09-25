typedef struct SourceInfo {
  BSTR         FileName;
  unsigned int LineNumber;
  unsigned int ColumnNumber;
  unsigned int CharPosition;
  BSTR         Hash;
} SourceInfo;