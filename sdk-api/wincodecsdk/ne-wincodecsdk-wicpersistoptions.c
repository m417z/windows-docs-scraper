typedef enum WICPersistOptions {
  WICPersistOptionDefault = 0,
  WICPersistOptionLittleEndian = 0,
  WICPersistOptionBigEndian = 0x1,
  WICPersistOptionStrictFormat = 0x2,
  WICPersistOptionNoCacheStream = 0x4,
  WICPersistOptionPreferUTF8 = 0x8,
  WICPersistOptionMask = 0xffff
} ;