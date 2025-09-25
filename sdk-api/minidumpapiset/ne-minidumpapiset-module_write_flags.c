typedef enum _MODULE_WRITE_FLAGS {
  ModuleWriteModule = 0x0001,
  ModuleWriteDataSeg = 0x0002,
  ModuleWriteMiscRecord = 0x0004,
  ModuleWriteCvRecord = 0x0008,
  ModuleReferencedByMemory = 0x0010,
  ModuleWriteTlsData = 0x0020,
  ModuleWriteCodeSegs = 0x0040
} MODULE_WRITE_FLAGS;