typedef struct _DXGK_VALIDATESUBMITCOMMANDFLAGS {
  union {
    struct {
      UINT HardwareQueueSubmission : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_VALIDATESUBMITCOMMANDFLAGS;