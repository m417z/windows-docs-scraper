typedef enum WICProgressOperation {
  WICProgressOperationCopyPixels = 0x1,
  WICProgressOperationWritePixels = 0x2,
  WICProgressOperationAll = 0xffff,
  WICPROGRESSOPERATION_FORCE_DWORD = 0x7fffffff
} ;