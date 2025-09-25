typedef struct _IO_FOEXT_SHADOW_FILE {
  PFILE_OBJECT BackingFileObject;
  PVOID        BackingFltInstance;
} IO_FOEXT_SHADOW_FILE, *PIO_FOEXT_SHADOW_FILE;