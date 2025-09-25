typedef enum _WDF_FILEOBJECT_CLASS {
  WdfFileObjectInvalid = 0,
  WdfFileObjectNotRequired = 1,
  WdfFileObjectWdfCanUseFsContext = 2,
  WdfFileObjectWdfCanUseFsContext2 = 3,
  WdfFileObjectWdfCannotUseFsContexts = 4,
  WdfFileObjectCanBeOptional = 0x80000000
} WDF_FILEOBJECT_CLASS, *PWDF_FILEOBJECT_CLASS;