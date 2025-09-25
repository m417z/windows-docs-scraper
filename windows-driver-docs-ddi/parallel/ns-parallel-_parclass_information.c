typedef struct _PARCLASS_INFORMATION {
  PUCHAR                    Controller;
  ULONG                     SpanOfController;
  PDETERMINE_IEEE_MODES     DetermineIeeeModes;
  PNEGOTIATE_IEEE_MODE      NegotiateIeeeMode;
  PTERMINATE_IEEE_MODE      TerminateIeeeMode;
  PPARALLEL_IEEE_FWD_TO_REV IeeeFwdToRevMode;
  PPARALLEL_IEEE_REV_TO_FWD IeeeRevToFwdMode;
  PPARALLEL_READ            ParallelRead;
  PPARALLEL_WRITE           ParallelWrite;
  PVOID                     ParclassContext;
  ULONG                     HardwareCapabilities;
  ULONG                     FifoDepth;
  ULONG                     FifoWidth;
} PARCLASS_INFORMATION, *PPARCLASS_INFORMATION;