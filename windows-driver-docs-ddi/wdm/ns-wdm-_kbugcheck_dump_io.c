typedef struct _KBUGCHECK_DUMP_IO {
  IN ULONG64                Offset;
  IN PVOID                  Buffer;
  IN ULONG                  BufferLength;
  IN KBUGCHECK_DUMP_IO_TYPE Type;
} KBUGCHECK_DUMP_IO, *PKBUGCHECK_DUMP_IO;