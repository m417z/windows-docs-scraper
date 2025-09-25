typedef struct _D3DKMT_NOTIFY_WORK_SUBMISSION_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} D3DKMT_NOTIFY_WORK_SUBMISSION_FLAGS;