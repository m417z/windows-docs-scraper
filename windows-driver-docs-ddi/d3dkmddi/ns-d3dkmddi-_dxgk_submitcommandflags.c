typedef struct _DXGK_SUBMITCOMMANDFLAGS {
  union {
    struct {
      UINT Paging : 1;
      UINT Present : 1;
      UINT RedirectedPresent : 1;
      UINT NullRendering : 1;
      UINT Flip : 1;
      UINT FlipWithNoWait : 1;
      UINT ContextSwitch : 1;
      UINT Resubmission : 1;
      UINT VirtualMachineData : 1;
#if ...
      UINT Reserved : 23;
#elif
      UINT Reserved : 24;
#elif
      UINT Reserved : 25;
#else
      UINT Reserved : 26;
#endif
    };
    UINT Value;
  };
} DXGK_SUBMITCOMMANDFLAGS;