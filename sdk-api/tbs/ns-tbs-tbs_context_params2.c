typedef struct tdTBS_CONTEXT_PARAMS2 {
    UINT32 version;
  union {
    struct {
      UINT32 requestRaw : 1;
      UINT32 includeTpm12 : 1;
      UINT32 includeTpm20 : 1;
    };
      UINT32 asUINT32;
  };
} TBS_CONTEXT_PARAMS2, *PTBS_CONTEXT_PARAMS2;