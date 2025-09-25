typedef enum _RTL_MEMORY_TYPE {
  MemoryTypePaged,
  MemoryTypeNonPaged,
  MemoryType64KPage,
  MemoryTypeLargePage,
  MemoryTypeHugePage,
  MemoryTypeCustom,
  MemoryTypeMax
} RTL_MEMORY_TYPE, *PRTL_MEMORY_TYPE;