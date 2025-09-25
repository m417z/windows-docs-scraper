typedef struct tagDBPARAMETER {
  LPOLESTR     pwszName;
  ITypeInfo    *pTypeInfo;
  DB_NUMERIC   *pNum;
  DBLENGTH     cbMaxLength;
  DBPARAMFLAGS dwFlags;
  DBTYPE       wType;
} DBPARAMETER;