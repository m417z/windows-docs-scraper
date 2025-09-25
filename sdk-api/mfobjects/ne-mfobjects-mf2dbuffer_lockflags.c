typedef enum _MF2DBuffer_LockFlags {
  MF2DBuffer_LockFlags_LockTypeMask,
  MF2DBuffer_LockFlags_Read = 0x1,
  MF2DBuffer_LockFlags_Write = 0x2,
  MF2DBuffer_LockFlags_ReadWrite = 0x3,
  MF2DBuffer_LockFlags_ForceDWORD = 0x7fffffff
} MF2DBuffer_LockFlags;